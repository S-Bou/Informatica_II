/**
   @file main.c

   @brief Plantilla Keil 5 para la placa STM32F$Discovery
   Más detalles en el archivo leeme.txt
   
   @author Equipo ARM Power http://armpower.blogs.upv.es/
   @date 2017/03/06
*/

#include <stdio.h>
#include <stm32f4xx.h>

int main(void)
{
   
   int32_t i = 0;
   uint32_t j;
   
   while (1) {
      for (j=0;j<1000000;j++) {};
      printf("Contador %d\n",i);
      i++;
      }      

   return(0);
}

