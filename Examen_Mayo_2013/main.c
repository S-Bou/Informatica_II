/**
   @file main.c

   @brief Plantilla Keil 5 para la placa STM32F$Discovery
   Más detalles en el archivo leeme.txt
   
   @author Equipo ARM Power http://armpower.blogs.upv.es/
   @date 2017/03/06
*/


#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx.h>

void init_entradas(void)
{
	//Definir los pines PA0, PA1 y PA2 como entradas digitales
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef puerto;
	puerto.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2; 
	puerto.GPIO_Mode = GPIO_Mode_IN; 
	puerto.GPIO_PuPd = GPIO_PuPd_NOPULL; 
	GPIO_Init(GPIOA, &puerto);
}

void init_salidas(void)
{
	//Definir los pines PD15, PD13 y PD12 como salidas digitales
		/*Configure GPIO pins: GreenLed_Pin OrangeLed_Pin RedLed_Pin BlueLed_Pin */
	GPIO_InitTypeDef puerto;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);  
	puerto.GPIO_Pin   = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	puerto.GPIO_Mode  = GPIO_Mode_OUT;
	puerto.GPIO_OType = GPIO_OType_PP; 
	puerto.GPIO_Speed = GPIO_Speed_100MHz;  
	puerto.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &puerto);
}

int main(void)
{
   

 

}

