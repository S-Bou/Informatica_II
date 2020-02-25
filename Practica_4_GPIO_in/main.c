/**
   @file main.c

   @brief Plantilla Keil 5 para la placa STM32F$Discovery
   Más detalles en el archivo leeme.txt
   
   @author Equipo ARM Power http://armpower.blogs.upv.es/
   @date 2017/03/06
*/

#include <stdio.h>
#include <stm32f4xx.h>
#include "mygpio.h"

void Configurar_interrupcion(void)
{
	GPIO_InitTypeDef cucaracha;
	NVIC_InitTypeDef gato;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  cucaracha.GPIO_Mode  = GPIO_Mode_IN;
  cucaracha.GPIO_PuPd = GPIO_PuPd_NOPULL;
  cucaracha.GPIO_Pin = GPIO_Pin_0;
  GPIO_Init(GPIOA, &cucaracha);
	
	RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising; 
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	XTI_Init(&EXTI_InitStructure);




}


int main(void)
{
   GPIO_Output_Config();
	 GPIO_Input_Config();
	Configurar_interrupcion();

   
   while (1) {
				
		 if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
		 {
		 GPIO_SetBits(GPIOD, GPIO_Pin_12);
		 }
		 GPIO_ResetBits(GPIOD, GPIO_Pin_12);
	 }
   return(0);
}

