/**
  ******************************************************************************
  * @file    main.c
  * @author  Khardani Majdi
  * @brief   GPIO Driver
  * @version V1.0.0
  * @date    16-10-2022
  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
#include "led.h"    
/* Private define ------------------------------------------------------------*/

int main()
{
  
  InputOutputConfig(GPIOA,PIN0, INPUT);
  ButtonToggleLed(GPIOD,PIN12,OUTPUT);
  
  while(1)
  {
  }
}