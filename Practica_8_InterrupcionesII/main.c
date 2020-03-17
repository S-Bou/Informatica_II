/**
   @file main.c

   @brief Plantilla Keil 5 para la placa STM32F$Discovery
   Más detalles en el archivo leeme.txt
   
   @author Equipo ARM Power http://armpower.blogs.upv.es/
   @date 2017/03/06
*/

#define M 1000000

#include <stdio.h>
#include <stm32f4xx.h>
#include "myconfig.h"

int i;

int main(void)
{
	GPIO_Output_Config();
	GPIO_Input_Config();
	EXT_INT_Config();
   
  while (1) 
	{
		for(i=0; i<10*M; i++)
		{
			NVIC_DisableIRQ(EXTI0_IRQn);
			GPIO_SetBits(GPIOD, GPIO_Pin_14);		 //Red led on
			GPIO_ResetBits(GPIOD, GPIO_Pin_12);  //Green led off
		}
		NVIC_EnableIRQ(EXTI0_IRQn);
		GPIO_ResetBits(GPIOD, GPIO_Pin_14);	 //Red led off
		GPIO_SetBits(GPIOD, GPIO_Pin_12);    //Green led on
		
		for(i=0; i<10*M; i++){}
	}      
}

