#include "TIMER.h"

/*User shall declare the call function */
extern void SWPWM_TimerInterrupt_CallBack(void);  

/*Replace the NULL PTR with the user notification call beack function */
Ptr2FuncType TIMER_Ptr2_TIM_UserNotification[] ={
    SWPWM_TimerInterrupt_CallBack,                /*CallBack function for Timer0 Interrupt*/
    NULL_PTR                                      /*CallBack function for Timer1 Interrupt*/
    } ;
