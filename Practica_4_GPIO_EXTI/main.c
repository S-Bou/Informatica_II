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

int numero_de_pulsaciones;

int main(void)
{
   GPIO_Output_Config();
	 GPIO_Input_Config();
	 EXT_INT_Config();

   
   while(1)
	 {		
		printf("El numero de pulsaciones es: %d \r\n",numero_de_pulsaciones); 
	 }
}

