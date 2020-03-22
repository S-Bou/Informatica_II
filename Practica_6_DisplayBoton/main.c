/**
   @file main.c

   @brief Plantilla Keil 5 para la placa STM32F$Discovery
   Más detalles en el archivo leeme.txt
   
   @author Equipo ARM Power http://armpower.blogs.upv.es/
   @date 2017/03/06
*/

#include <stm32f4xx.h>
#include "myconfig.h"

uint64_t i, j;

int main(void)
{
	GPIO_Output_Config();
	EXT_INT_Config();
  DisplayConfig(); 
	
	while(1)
	{
		for (i=0; i<9; i++)
		{
			Mostrar(i);
			for (j=0; j<300000; j++) {};
		}
		for (i=9; i>0; i--)
		{
			Mostrar(i);
			for (j=0; j<300000; j++) {};
		}
	}
}


// https://polilabs.upv.es/login/


