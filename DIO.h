#ifndef DIO_H
#define DIO_H

#include "Std_Types.h"

#define DIO_PIN_INPUT_ANALOG            0b00000000u
#define DIO_PIN_INPUT_FLOATING          0b00000100u
#define DIO_PIN_INPUT_PULL              0b00001000u

#define DIO_PIN_OUTPUT_PUSH_PULL        0b00000001u  /*Max speed 10 MHz*/
#define DIO_PIN_OUTPUT_OPEN_DRAIN       0b00000101u  /*Max speed 10 MHz*/
#define DIO_PIN_OUTPUT_AF_PUSHPULL      0b00001001u  /*Max speed 10 MHz*/
#define DIO_PIN_OUTPUT_AF_OPENDRAIN     0b00001101u  /*Max speed 10 MHz*/


#define DIO_PORT_A                      0u
#define DIO_PORT_B                      1u
#define DIO_PORT_C                      2u
#define DIO_PORT_D                      3u
#define DIO_PORT_E                      4u
#define DIO_PORT_F                      5u
#define DIO_PORT_G                      6u

void DIO_init(uint8 pinNumber, uint8 port, uint8 direction);
void DIO_write(uint8 pinNumber, uint8 port, uint8 value);
void DIO_toggle(uint8 pinNumber, uint8 port);

#endif
