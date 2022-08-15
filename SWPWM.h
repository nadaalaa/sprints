#ifndef SWPWM_H
#define SWPWM_H

#include "Std_Types.h"
#include "TIMER.h"
#include "SWPWM_Cfg.h"

void SWPWM_init(uint32 frequesncy_kh, uint8 dutyCycle);
void SWPWM_start(void);
void SWPWM_changeDutyCycle(uint8 newDutyCycle);
void SWPWM_stop(void);

#endif
