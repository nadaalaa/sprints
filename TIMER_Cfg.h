#ifndef TIMER_CFG_H
#define TIMER_CFG_H
/*
* Please choose one of the following
* TIMER_MODE_ONE_SHOT        
* TIMER_MODE_CONTINOUS       
**/
#define TIMER_MODE_SELECTOR                TIMER_MODE_CONTINOUS     
/* The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1). 
 the internal clock is used to clock the timer prescaler */    
#define TIMER_PRESCALER_CFG            16uL /*Configure it to make the timer clock = 1MHz assuming the Internal CLock is 16MHz*/

#define TIMER_PTR2USERNOTIFICATION_TIM0   User_CallBack_0
#define TIMER_PTR2USERNOTIFICATION_TIM1   User_CallBack_1

#endif /*TIMER_CFG_H*/