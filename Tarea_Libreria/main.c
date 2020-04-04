/**
   @file   main.c
   @brief  Tarea librería para display de siete segmentos.
	         Con esta librería se ha de definir en el vector "vector_pin_t"
					 cualquier pin de cualquier puerto donde se desea conectar el display.
					 El display ha de ser de cátodo (-) común.
   @author Sergio Bou Grau
   @date   04/04/2020
*/

#include <stm32f4xx.h>
#include "myconfig.h"	//Librería para configurar la interrupción

#include "lib_7seg.h"

	vector_pin_t v={{GPIOA, GPIO_Pin_4},		// segmento a
									{GPIOA, GPIO_Pin_12},		// segmento b
									{GPIOB, GPIO_Pin_0},		// segmento c
									{GPIOC, GPIO_Pin_1}, 		// segmento d
									{GPIOC, GPIO_Pin_9}, 		// segmento e
									{GPIOD, GPIO_Pin_5},		// segmento f
									{GPIOE, GPIO_Pin_11}, 	// segmento g	
									{GPIOE, GPIO_Pin_14}};	// punto

int main(void)
{		
	
	EXT_INT_Config();	/*Configura una interrupcion externa en 
	                    el pin PA0 para el boton azul*/
									
	init_library(v);	//Configura los pines para el display
	
	display(0, v);		//Inicializa el display

}




