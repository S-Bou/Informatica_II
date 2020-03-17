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

volatile uint8_t muestreo = 0;
extern uint8_t pulsaciones;
int i;

int main(void)
{
	GPIO_Input_Config();
	Configurar_interrupcion();     
	while (1)
	{
		if(muestreo != pulsaciones)
		{
			muestreo = pulsaciones;
			printf("Muestreo: %d\n", muestreo);
		}
		for(i=0; i<50000000; i++){}
	}
}

