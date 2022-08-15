#include "Mcu_Hw.h"
#include "DIO.h"

static const uint32 DIO_Gpio_BaseAddress[]={DIO_PORT_A_BASE_ADDRESS,DIO_PORT_B_BASE_ADDRESS,DIO_PORT_C_BASE_ADDRESS
                                            DIO_PORT_D_BASE_ADDRESS,DIO_PORT_E_BASE_ADDRESS,DIO_PORT_F_BASE_ADDRESS,DIO_PORT_G_BASE_ADDRESS};
void DIO_init(uint8 pinNumber, uint8 port, uint8 direction)
{
    if(pinNumber/8 == 0)
    {
        GPIO_CRL(port) |= ((uint32)direction<<(pinNumber*4));
    }
    else
    {
        GPIO_CRH(port) |= ((uint32)direction<<(pinNumber*4));
    }

}
void DIO_write(uint8 pinNumber, uint8 port, uint8 value)
{
    if(value == STD_HIGH)
    {
        GPIO_ODR(DIO_Gpio_BaseAddress[port]) |= ((uint16)1<<pinNumber);
    }
    else if(value == STD_LOW)
    {
         GPIO_ODR(DIO_Gpio_BaseAddress[port]) &= ~((uint16)1<<pinNumber);
    }
    else
    {
        /*report Error*/
    }
    
}
void DIO_toggle(uint8 pinNumber, uint8 port)
{
    GPIO_ODR(DIO_Gpio_BaseAddress[port]) ^= ((uint16)1<<pinNumber);
}