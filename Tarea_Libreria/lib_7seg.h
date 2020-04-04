/**
   @file   lib_7seg.h
   @brief  Módulo para representar dígitos en display de siete segmentos.  
   @author Sergio Bou Grau
   @date   04/04/2020
*/
#ifndef __LIB_7SEG_H__
#define __LIB_7SEG_H__

#include <stm32f4xx.h> 

typedef struct pin_map_dummy {
  GPIO_TypeDef* GPIO_Port;
	uint16_t GPIO_Pin;
} pin_map_t;

typedef pin_map_t vector_pin_t[8]; // array de 8 componentes definen cada pin.

void init_library(vector_pin_t pines);
void display(uint8_t num, vector_pin_t); 

#endif /*__LIB_7SEG_H__*/



