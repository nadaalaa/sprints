#include "TIMER.h"
#include "SWPWM.h"

typedef enum
{
    SWPWM_RisingEdge=0,
    SWPWM_FailingEdge
}SWPWM_EdgeType;


static uint16 SWPWM_tonSteps,SWPWM_toffSteps;

void SWPWM_init(uint32 frequesncy_kh, uint8 dutyCycle)
{
    /* Init Dio Pin with Initialized level (Low)*/
    Dio_WriteChannel(SWPWM_OUTPUT_PIN_SELECTOR, STD_LOW);
    /*Init the configuredd timer */
     TIMER_init(SWPWM_TIMER_SELECTOR);
     
     SWPWM_changeDutyCycle(dutyCycle);
}
void SWPWM_start(void)
{
    TIMER_start(SWPWM_TIMER_SELECTOR);
}
void SWPWM_changeDutyCycle(uint8 newDutyCycle)
{
    static uint32 SWPWM_Ton_us,SWPWM_Toff_us;
    if(newDutyCycle <= 100)
    {
        SWPWM_Ton_us = (SWPWM_PWM_TOTAL_PERIOD_TIME_US*newDutyCycle)/100;
        SWPWM_Toff_us =  SWPWM_PWM_TOTAL_PERIOD_TIME_US - SWPWM_Ton_us;

         /* Calculate TonSteps and ToffSteps*/
         SWPWM_tonSteps = SWPWM_Ton_us*SWPWM_TIMER_FREQ_MHz;
         SWPWM_toffSteps = SWPWM_Toff_us*SWPWM_TIMER_FREQ_MHz;
    }
    else
    {
        /* Report error */
    }
}

void SWPWM_stop(void)
{
    TIMER_stop(SWPWM_TIMER_SELECTOR);
}

/*The SWPWM_TimerInterrupt_CallBack shall be provided to the Timer_Cfg.c as a user notification for selected timer */
void SWPWM_TimerInterrupt_CallBack(void)
{
    static SWPWM_EdgeType SWPWM_CurrentEdge = SWPWM_RisingEdge;

    switch(SWPWM_CurrentEdge)
    {
        case SWPWM_RisingEdge:
            Dio_WriteChannel(SWPWM_OUTPUT_PIN_SELECTOR, STD_HIGH);
            TIMER_set(SWPWM_TIMER_SELECTOR, SWPWM_tonSteps);
            SWPWM_CurrentEdge = SWPWM_FailingEdge;
        break;
        case SWPWM_FailingEdge:
            Dio_WriteChannel(SWPWM_OUTPUT_PIN_SELECTOR, STD_LOW);
            TIMER_set(SWPWM_TIMER_SELECTOR, SWPWM_toffSteps);
            SWPWM_CurrentEdge = SWPWM_RisingEdge;
        break;
    }

}