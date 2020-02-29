/**
   @file binario.c
   @brief Ejemplo basico para explicar bibliotecas
   
   @author El equipo ARM Cortex-M http://armcortexm.blogs.upv.es
   @date 2013/03/04

*/

#include "binario.h"


/*************************************************************************************************/
/**
  * @brief  Funcion conv binario
  * @param  dato
  * @retval Nada
  */

void binario(uint16_t num)
{
   int aux;
   static int nr = 0;
   
if(num==0) {//<-La funcion recursiva tiene como condicion de salida,
         //cuando el numero es cero
   while(nr<16) {printf("%d",0); nr++;}
   return;}
           //si no
   nr++;
   aux=num%2;//<-"guardamos" el residuo de la divicion
   num=num/2;//<-actualizamos el valor del numero, para la proxima llamada
             //recursiva
   binario(num);//<-hacemos la sig llamada recursiva con nuestro valor actualizado
   printf("%d",aux);//<-Al poner la llamada de impresion despues de la llamada
                    //recursiva sig, hacemos que imprima primero las llamadas
                    //que se realizaron al final, haciendo el efecto de imprimir
                //inversamente
} 


/*** Fin del archivo *****************************************************************************/
