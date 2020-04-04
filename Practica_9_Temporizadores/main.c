/**
   @file main.c

   @brief Plantilla Keil 5 para la placa STM32F$Discovery
   Más detalles en el archivo leeme.txt
   
   @author Equipo ARM Power http://armpower.blogs.upv.es/
   @date 2017/03/06
*/

#include <stdio.h>
#include <stm32f4xx.h>
#include "myconfig.h"

int main(void)
{
	GPIO_Output_Config(); //Configura los cuatro leds
	GPIO_Input_Config();  //Configura el pulsador
	EXT_INT_Config();			//Configura las interrupciones externas
   
	while (1) 
	{
		
	}      
}

