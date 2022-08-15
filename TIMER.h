#ifndef TIMER_H
#define TIMER_H

#include "Std_Types.h"
#include "Timer_Cfg.h"

typedef uint8 TIMER_IdType;
#define TIMER_ID_0            0u  /*STM32 TIM6*/
#define TIMER_ID_1            1u  /*STM32 TIM7*/


Std_ReturnType TIMER_init(TIMER_IdType TimerId);
Std_ReturnType TIMER_set(TIMER_IdType TimerId, uint16 ReloadValue);
Std_ReturnType TIMER_stop(TIMER_IdType TimerId);
Std_ReturnType TIMER_getstate(TIMER_IdType TimerId, uint16* CounterValue);
Std_ReturnType TIMER_start(TIMER_IdType TimerId);



#endif /*TIMER_H*/
