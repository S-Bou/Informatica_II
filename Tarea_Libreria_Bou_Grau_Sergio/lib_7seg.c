/**
   @file   lib_7seg.c
   @brief  Módulo para representar dígitos en display de siete segmentos.  
   @author Sergio Bou Grau
   @date   04/04/2020
*/
/*
	Dígito 	|	 a   b   c   d   e   f   g  punto
	-------------------------------------------
     0    |	 1   1   1   1   1   1   0    0
     1    |	 0   1   1   0   0   0   0    0
		 2    |	 1   1   0   1   1   0   1    0
		 3    |	 1   1   1   1   0   0   1    0
		 4    |	 0   1   1   0   0   1   1    0
		 5    |	 1   0   1   1   0   1   1    0
	   6    |	 1   0   1   1   1   1   1    0													
     7    |	 1   1   1   0   0   0   0    0
     8    |	 1   1   1   1   1   1   1    0
     9    |	 1   1   1   0   0   1   1    0
  punto   |	 0   0   0   0   0   0   0    1
*/

#include <lib_7seg.h>
/*#################################################################################################*/
void init_library(vector_pin_t pines)
{
	uint8_t i;
	
	for(i=0; i<8; i++){
		
		GPIO_InitTypeDef display;
		
		if      (pines[i].GPIO_Port == GPIOA){
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
			
		}else if(pines[i].GPIO_Port == GPIOB){
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
			
		}else if(pines[i].GPIO_Port == GPIOC){
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
			
		}else if(pines[i].GPIO_Port == GPIOD){
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

		}else if(pines[i].GPIO_Port == GPIOE){
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
		}
							
		display.GPIO_Pin   = pines[i].GPIO_Pin;
		display.GPIO_Mode  = GPIO_Mode_OUT;
		display.GPIO_OType = GPIO_OType_OD;
		display.GPIO_Speed = GPIO_Speed_25MHz;
		display.GPIO_PuPd  = GPIO_PuPd_UP;
		GPIO_Init(pines[i].GPIO_Port, &display);
	}
}

/*#################################################################################################*/
void display(uint8_t num, vector_pin_t pines)
{
	switch (num)
	{
	case 0: 
		GPIO_SetBits(pines[0].GPIO_Port, pines[0].GPIO_Pin);		// segmento a
		GPIO_SetBits(pines[1].GPIO_Port, pines[1].GPIO_Pin); 		// segmento b
		GPIO_SetBits(pines[2].GPIO_Port, pines[2].GPIO_Pin); 		// segmento c
		GPIO_SetBits(pines[3].GPIO_Port, pines[3].GPIO_Pin); 		// segmento d
		GPIO_SetBits(pines[4].GPIO_Port, pines[4].GPIO_Pin); 		// segmento e
		GPIO_SetBits(pines[5].GPIO_Port, pines[5].GPIO_Pin); 		// segmento f
		GPIO_ResetBits(pines[6].GPIO_Port, pines[6].GPIO_Pin); 	// segmento g
		GPIO_ResetBits(pines[7].GPIO_Port, pines[7].GPIO_Pin); 	// punto
		break;
	case 1: 
		GPIO_ResetBits(pines[0].GPIO_Port, pines[0].GPIO_Pin);	// segmento a
		GPIO_SetBits(pines[1].GPIO_Port, pines[1].GPIO_Pin); 		// segmento b
		GPIO_SetBits(pines[2].GPIO_Port, pines[2].GPIO_Pin); 		// segmento c
		GPIO_ResetBits(pines[3].GPIO_Port, pines[3].GPIO_Pin); 	// segmento d
		GPIO_ResetBits(pines[4].GPIO_Port, pines[4].GPIO_Pin); 	// segmento e
		GPIO_ResetBits(pines[5].GPIO_Port, pines[5].GPIO_Pin); 	// segmento f
		GPIO_ResetBits(pines[6].GPIO_Port, pines[6].GPIO_Pin); 	// segmento g
		GPIO_ResetBits(pines[7].GPIO_Port, pines[7].GPIO_Pin); 	// punto
		break;
	case 2:
		GPIO_SetBits(pines[0].GPIO_Port, pines[0].GPIO_Pin);		// segmento a
		GPIO_SetBits(pines[1].GPIO_Port, pines[1].GPIO_Pin); 		// segmento b
		GPIO_ResetBits(pines[2].GPIO_Port, pines[2].GPIO_Pin); 	// segmento c
		GPIO_SetBits(pines[3].GPIO_Port, pines[3].GPIO_Pin); 		// segmento d
		GPIO_SetBits(pines[4].GPIO_Port, pines[4].GPIO_Pin); 		// segmento e
		GPIO_ResetBits(pines[5].GPIO_Port, pines[5].GPIO_Pin); 	// segmento f
		GPIO_SetBits(pines[6].GPIO_Port, pines[6].GPIO_Pin); 	  // segmento g
		GPIO_ResetBits(pines[7].GPIO_Port, pines[7].GPIO_Pin); 	// punto
		break;
	case 3:
		GPIO_SetBits(pines[0].GPIO_Port, pines[0].GPIO_Pin);		// segmento a
		GPIO_SetBits(pines[1].GPIO_Port, pines[1].GPIO_Pin); 		// segmento b
		GPIO_SetBits(pines[2].GPIO_Port, pines[2].GPIO_Pin); 		// segmento c
		GPIO_SetBits(pines[3].GPIO_Port, pines[3].GPIO_Pin); 		// segmento d
		GPIO_ResetBits(pines[4].GPIO_Port, pines[4].GPIO_Pin); 	// segmento e
		GPIO_ResetBits(pines[5].GPIO_Port, pines[5].GPIO_Pin); 	// segmento f
		GPIO_SetBits(pines[6].GPIO_Port, pines[6].GPIO_Pin); 	  // segmento g
		GPIO_ResetBits(pines[7].GPIO_Port, pines[7].GPIO_Pin); 	// punto
		break;
	case 4:
		GPIO_ResetBits(pines[0].GPIO_Port, pines[0].GPIO_Pin);	// segmento a
		GPIO_SetBits(pines[1].GPIO_Port, pines[1].GPIO_Pin); 		// segmento b
		GPIO_SetBits(pines[2].GPIO_Port, pines[2].GPIO_Pin); 		// segmento c
		GPIO_ResetBits(pines[3].GPIO_Port, pines[3].GPIO_Pin); 	// segmento d
		GPIO_ResetBits(pines[4].GPIO_Port, pines[4].GPIO_Pin); 	// segmento e
		GPIO_SetBits(pines[5].GPIO_Port, pines[5].GPIO_Pin); 		// segmento f
		GPIO_SetBits(pines[6].GPIO_Port, pines[6].GPIO_Pin); 	  // segmento g
		GPIO_ResetBits(pines[7].GPIO_Port, pines[7].GPIO_Pin); 	// punto
		break;
	case 5:
		GPIO_SetBits(pines[0].GPIO_Port, pines[0].GPIO_Pin);		// segmento a
		GPIO_ResetBits(pines[1].GPIO_Port, pines[1].GPIO_Pin); 	// segmento b
		GPIO_SetBits(pines[2].GPIO_Port, pines[2].GPIO_Pin); 		// segmento c
		GPIO_SetBits(pines[3].GPIO_Port, pines[3].GPIO_Pin); 		// segmento d
		GPIO_ResetBits(pines[4].GPIO_Port, pines[4].GPIO_Pin); 	// segmento e
		GPIO_SetBits(pines[5].GPIO_Port, pines[5].GPIO_Pin); 		// segmento f
		GPIO_SetBits(pines[6].GPIO_Port, pines[6].GPIO_Pin); 	  // segmento g
		GPIO_ResetBits(pines[7].GPIO_Port, pines[7].GPIO_Pin); 	// punto
		break;
	case 6:
		GPIO_SetBits(pines[0].GPIO_Port, pines[0].GPIO_Pin);		// segmento a
		GPIO_ResetBits(pines[1].GPIO_Port, pines[1].GPIO_Pin); 	// segmento b
		GPIO_SetBits(pines[2].GPIO_Port, pines[2].GPIO_Pin); 		// segmento c
		GPIO_SetBits(pines[3].GPIO_Port, pines[3].GPIO_Pin); 		// segmento d
		GPIO_SetBits(pines[4].GPIO_Port, pines[4].GPIO_Pin); 		// segmento e
		GPIO_SetBits(pines[5].GPIO_Port, pines[5].GPIO_Pin); 		// segmento f
		GPIO_SetBits(pines[6].GPIO_Port, pines[6].GPIO_Pin); 	  // segmento g
		GPIO_ResetBits(pines[7].GPIO_Port, pines[7].GPIO_Pin); 	// punto
		break;
	case 7:
		GPIO_SetBits(pines[0].GPIO_Port, pines[0].GPIO_Pin);		// segmento a
		GPIO_SetBits(pines[1].GPIO_Port, pines[1].GPIO_Pin); 		// segmento b
		GPIO_SetBits(pines[2].GPIO_Port, pines[2].GPIO_Pin); 		// segmento c
		GPIO_ResetBits(pines[3].GPIO_Port, pines[3].GPIO_Pin); 	// segmento d
		GPIO_ResetBits(pines[4].GPIO_Port, pines[4].GPIO_Pin); 	// segmento e
		GPIO_ResetBits(pines[5].GPIO_Port, pines[5].GPIO_Pin); 	// segmento f
		GPIO_ResetBits(pines[6].GPIO_Port, pines[6].GPIO_Pin); 	// segmento g
		GPIO_ResetBits(pines[7].GPIO_Port, pines[7].GPIO_Pin); 	// punto
		break;
	case 8:
		GPIO_SetBits(pines[0].GPIO_Port, pines[0].GPIO_Pin);		// segmento a
		GPIO_SetBits(pines[1].GPIO_Port, pines[1].GPIO_Pin); 		// segmento b
		GPIO_SetBits(pines[2].GPIO_Port, pines[2].GPIO_Pin); 		// segmento c
		GPIO_SetBits(pines[3].GPIO_Port, pines[3].GPIO_Pin); 		// segmento d
		GPIO_SetBits(pines[4].GPIO_Port, pines[4].GPIO_Pin); 		// segmento e
		GPIO_SetBits(pines[5].GPIO_Port, pines[5].GPIO_Pin); 		// segmento f
		GPIO_SetBits(pines[6].GPIO_Port, pines[6].GPIO_Pin); 	  // segmento g
		GPIO_ResetBits(pines[7].GPIO_Port, pines[7].GPIO_Pin); 	// punto
		break;
	case 9:
		GPIO_SetBits(pines[0].GPIO_Port, pines[0].GPIO_Pin);		// segmento a
		GPIO_SetBits(pines[1].GPIO_Port, pines[1].GPIO_Pin); 		// segmento b
		GPIO_SetBits(pines[2].GPIO_Port, pines[2].GPIO_Pin); 		// segmento c
		GPIO_SetBits(pines[3].GPIO_Port, pines[3].GPIO_Pin); 		// segmento d
		GPIO_ResetBits(pines[4].GPIO_Port, pines[4].GPIO_Pin); 	// segmento e
		GPIO_SetBits(pines[5].GPIO_Port, pines[5].GPIO_Pin); 		// segmento f
		GPIO_SetBits(pines[6].GPIO_Port, pines[6].GPIO_Pin); 	  // segmento g
		GPIO_ResetBits(pines[7].GPIO_Port, pines[7].GPIO_Pin); 	// punto
		break;
	case 10:
		GPIO_ResetBits(pines[0].GPIO_Port, pines[0].GPIO_Pin);		// segmento a
		GPIO_ResetBits(pines[1].GPIO_Port, pines[1].GPIO_Pin); 		// segmento b
		GPIO_ResetBits(pines[2].GPIO_Port, pines[2].GPIO_Pin); 		// segmento c
		GPIO_ResetBits(pines[3].GPIO_Port, pines[3].GPIO_Pin); 		// segmento d
		GPIO_ResetBits(pines[4].GPIO_Port, pines[4].GPIO_Pin); 		// segmento e
		GPIO_ResetBits(pines[5].GPIO_Port, pines[5].GPIO_Pin); 		// segmento f
		GPIO_ResetBits(pines[6].GPIO_Port, pines[6].GPIO_Pin); 	  // segmento g
		GPIO_SetBits(pines[7].GPIO_Port, pines[7].GPIO_Pin); 	    // punto
		break;
	default:   break;
	}
}
/*#################################################################################################*/


