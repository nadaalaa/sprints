#include "TIMER.h"
#include "Mcu_Hw.h"

#define NUMBER_OF_SUPPORTTED_TIMERS             2u

#define TIMER_MODE_ONE_SHOT                     0u
#define TIMER_MODE_CONTINOUS                    1u

extern Ptr2FuncType TIMER_Ptr2_TIM_UserNotification[];

static const uint32 TIMER_BaseAddr[NUMBER_OF_SUPPORTTED_TIMERS] = {TIMER_6_BASE_ADDRESS, TIMER_7_BASE_ADDRESS};
static uint8 TIMER_InitStatus[NUMBER_OF_SUPPORTTED_TIMERS] = {DISABLE,DISABLE};

Std_ReturnType TIMER_init(TIMER_IdType TimerId)
{
    Std_ReturnType RetVal = E_NOT_OK;
    if(TimerId < NUMBER_OF_SUPPORTTED_TIMERS)
    {
        /*#1 TODO: Enable Timer Clock From RCC */

        /*#2 Auto-reload preload enable */
        TIM_CR1(TIMER_BaseAddr[TimerId]).B.ARPE = ENABLE;
        /*#3Configure Timer mode */
        TIM_CR1(TIMER_BaseAddr[TimerId]).B.OPM = TIMER_MODE_SELECTOR;
        /*#4 Configure the prescaler */
        TIM_PSC(TIMER_BaseAddr[TimerId]) = TIMER_PRESCALER_CFG;
        /*#5Enable Interrupt*/
        TIM_DIER(TIMER_BaseAddr[TimerId]) = ENABLE;
        /*#6 mark that timer is initialized */
        TIMER_InitStatus[TimerId] = ENABLE;
    }
    return RetVal;
}
Std_ReturnType TIMER_set(TIMER_IdType TimerId, uint16 ReloadValue)
{
    Std_ReturnType RetVal = E_NOT_OK;
    if( (TimerId < NUMBER_OF_SUPPORTTED_TIMERS) &&
        (ReloadValue != 0)                      &&
        (TIMER_InitStatus[TimerId] == ENABLE))
    {   
        /* Set the Reload Value into register TIMx_ARR*/
        TIM_ARR(TIMER_BaseAddr[TimerId]) = ReloadValue;

        RetVal = E_OK;
    }
    return RetVal;
}
Std_ReturnType TIMER_stop(TIMER_IdType TimerId)
{
    Std_ReturnType RetVal = E_NOT_OK;
    if(TimerId < NUMBER_OF_SUPPORTTED_TIMERS)
    {
        /* disable the timer by disabling the prescaler clock*/
        TIM_CR1(TIMER_BaseAddr[TimerId]).B.CEN = DISABLE;

         RetVal = E_OK;
    }

    return RetVal;
}
Std_ReturnType TIMER_getstate(TIMER_IdType TimerId, uint16* Ptr2CounterValue)
{
    Std_ReturnType RetVal = E_NOT_OK;
    if( (TimerId < NUMBER_OF_SUPPORTTED_TIMERS) && 
        (Ptr2CounterValue != NULL_PTR)          &&
        (TIMER_InitStatus[TimerId] == ENABLE))
    {
        /* get the TIMx_CNT Value*/
        *Ptr2CounterValue = (uint16)TIM_CNT(TIMER_BaseAddr[TimerId]);
        
        RetVal = E_OK;
    }

    return RetVal;
}

Std_ReturnType TIMER_start(TIMER_IdType TimerId)
{
    Std_ReturnType RetVal = E_NOT_OK;
    if((TimerId < NUMBER_OF_SUPPORTTED_TIMERS) &&
        (TIMER_InitStatus[TimerId] == ENABLE))
    {
        /* As soon as the CEN bit is written to 1, the prescaler is clocked by the internal clock CK_INT*/
        TIM_CR1(TIMER_BaseAddr[TimerId]).B.CEN = ENABLE;
    }
}
void ISR_TIM6(void)
{
    if(TIMER_Ptr2_TIM_UserNotification[0] != NULL_PTR)
    {
        TIMER_Ptr2_TIM_UserNotification[0]();
    }
}

void ISR_TIM7(void)
{
    if(TIMER_Ptr2_TIM_UserNotification[1] != NULL_PTR)
    {
        TIMER_Ptr2_TIM_UserNotification[1]();
    }    
}