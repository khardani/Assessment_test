#ifndef __LED_H
#define __LED_

#include <stdint.h>


#define GPIOD      (uint32_t*)0x40020c00
#define GPIOA      (uint32_t*)0x40020000

#define PIN0                    0u
#define PIN12                   12u
#define PIN13                   13u
#define PIN14                   14u
#define PIN15                   15u


#define INPUT                   0x0u
#define OUTPUT                  0x1u
#define ALTERNATE               0x2u
#define ANALOG_INPUT            0x3u

#define SET                     1u
#define RESET                   0u
void ButtonToggleLed(uint32_t *GPIOx,uint8_t Pin,uint8_t Mode);
void InputOutputConfig(uint32_t *GPIOx,uint8_t Pin,uint8_t Mode);



#endif