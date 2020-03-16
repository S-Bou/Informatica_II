/**
   @file main.c

   @brief Plantilla Keil 5 para la placa STM32F$Discovery
   Más detalles en el archivo leeme.txt
   
   @author Equipo ARM Power http://armpower.blogs.upv.es/
   @date 2017/03/06
*/

#include <stm32f4xx.h>
#include "myconfig.h"

uint32_t i,j;

void displayConf(void);

int main(void)
{
  DisplayConfig();
	
  while(1)
	{
		for (i=0; i<9; i++)
		{
			Mostrar(i);
			printf("\n");
			for (j=0; j<10000000; j++) {};
		}
		for (i=9; i>0; i--)
		{
			Mostrar(i);
			printf("\n");
			for (j=0; j<10000000; j++) {};
		}
	}      
}





