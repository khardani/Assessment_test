#include "gpio.h"


#define OFFSET_ODR           (0x14/4)
#define OFFSET_IDR           (0X10/4)
void AssertValid(void)
{
  __asm("NOP");
}

void AssertFailed(void)
{
  while(1){}
}

#define EMB_ASSERT(Exp) ((Exp) ? AssertValid() : AssertFailed())


uint16_t *RCCAHB1 = (uint16_t *)(0x40023830);
void ButtonToggleLed(uint32_t *GPIOx,uint8_t Pin,uint8_t Mode)
{ 
  if(Mode == OUTPUT)
  {
   *(GPIOx + OFFSET_ODR) &= ~(1<<PIN15);
  *(GPIOx + OFFSET_ODR) |=  (1<<PIN15); 
  }
   uint8_t  readpin = ((*(GPIOx + OFFSET_IDR) >> PIN0) & 1) ;
  if(readpin == 1 )  {
   *(GPIOx + OFFSET_ODR) &= ~(1<<PIN12);
  *(GPIOx + OFFSET_ODR) |=  (1<<PIN12);
  }
  else 
       {
    *(GPIOx + OFFSET_ODR) &= ~(0<<PIN12);
   *(GPIOx + OFFSET_ODR) |=  (0<<PIN12);
        }
    
}
void InputOutputConfig(uint32_t *GPIOx,uint8_t Pin,uint8_t Mode)
{
   EMB_ASSERT( GPIOx == GPIOD || GPIOA );
   EMB_ASSERT(Pin >= PIN0 && Pin <= PIN15);
   EMB_ASSERT(Mode == OUTPUT || Mode == INPUT);
   if(GPIOx == GPIOA)
   {    
 *GPIOx &= ~(0x3 << PIN0);
 *GPIOx |= (INPUT  << PIN0);
   } 
   else if(GPIOx == GPIOD)
   {
     *GPIOx &= ~(0x3 <<PIN12);
     *GPIOx |= (OUTPUT  << PIN12);
     *GPIOx &= ~(0x3 <<PIN15);
     *GPIOx |= (OUTPUT  << PIN15);
   }
 
     }
    
 
