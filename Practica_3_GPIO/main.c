#include <stdint.h>
#include <stm32f4xx.h> 
#include <stm32f4xx_gpio.h> 
#include <stm32f4xx_rcc.h> 
#include "mygpio.h"

uint32_t cara = 1, r=0, j;            //    ccc-cccc 
//uint8_t figuras[6] = {
//											0x08,  //1 - 000-   1000  
//											0x11,  //2 - 001-   0001  
//											0x19,  //3 - 001-   1001
//											0x55,  //4 - 101-   0101
//											0x5D,  //5 - 101-   1101
//											0x77,  //6 - 111-   0111 
//											}; 

//void visualizarDado(uint8_t c) 
//{
//   GPIO_Write(GPIOD, figuras[c - 1]); 
//} 

int main(void) {
		
	GPIO_Output_Config();
	GPIO_Input_Config();
	
	while(1)
	{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)) 
	  {
			 r=(r+1)%5;
			 for (j=0; j<2000000; j++) {};										//This prevent bounces
			 while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0));
			 for (j=0; j<2000000; j++) {};												  
		}
		
		GPIO_SetBits(GPIOD, GPIO_Pin_12);
		for (j=0;j<1000000+2000000*r;j++) {};
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);
		for (j=0;j<1000000+2000000*r;j++) {};		
	}
}

