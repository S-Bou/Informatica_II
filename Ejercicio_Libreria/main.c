/**
   @file main.c

   @brief Plantilla Keil 5 para la placa STM32F$Discovery
   Más detalles en el archivo leeme.txt
   
   @author Equipo ARM Power http://armpower.blogs.upv.es/
   @date 2017/03/06
*/

#include <stdio.h>
#include <stm32f4xx.h>
#include "aritmetica.h"

int main(void)
{
	int a = 30000;
	int b = 35;
	
  printf("El tamño en memoria de tipo numerio_t es %d bytes\n", sizeof(numero_t));
	printf("Operaciones\n");
	printf("%d+%d=%d\n", a, b, suma(a, b));
	printf("%d-%d=%d\n", a, b, resta(a, b));
	printf("%d*%d=%d\n", a, b, multiplicacion(a, b));
	printf("%d/%d=%d\n", a, b, division(a, b));
    
}

