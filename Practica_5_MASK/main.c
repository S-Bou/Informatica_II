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
#include "binario.h"

void ConmpruebaBits(uint16_t);

uint16_t dato = 0x0006;
uint64_t resultado;
int j;

int main(void)
{
   
	while (1) 
	{
		printf("Dato inicial: ");
		binario(dato);
		printf("\n");
		for (j=0; j<20000000; j++) {};
		printf("Resultado:    ");
		resultado =~ (dato << 12);
		binario(resultado);
		printf("\n");
		for (j=0; j<20000000; j++) {};
			
		/* Ejercicio 2 */
		
		resultado &=~ 0x0004; 
		printf("Ejercicio 2:  ");
		binario(resultado);
		printf("\n");
		for (j=0; j<20000000; j++) {};
		
		/* Ejercicio 3 */
		printf("Primera comprobacion...\n");
		ConmpruebaBits(0xDEFE);		//0b1101111011111110
		printf("Segunda comprobacion...\n");
		ConmpruebaBits(0xDEFF);		//0b1101111011111111
	}      

}

void ConmpruebaBits(uint16_t data)
{
	uint16_t aux = data & 0x2101;
	if(aux == 0)
	{
		printf("Los bits 14, 9 y 1 estan en 0\n");
		
	}else
	{
		printf("Algun/os bits 14, 9 y 1 estan en 1\n");
	}
}

