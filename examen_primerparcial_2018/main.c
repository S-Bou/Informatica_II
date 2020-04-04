#include <stdint.h>
#include <stm32f4xx.h> 
#include <stm32f4xx_gpio.h> 
#include <stm32f4xx_rcc.h> 



void inicializar_semaforo(void)
{
	
	GPIO_InitTypeDef puerto;  
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);  
	
	puerto.GPIO_Pin  = GPIO_Pin_5 | GPIO_Pin_6; 
  puerto.GPIO_Mode  = GPIO_Mode_OUT;
	puerto.GPIO_OType = GPIO_OType_PP; 
  puerto.GPIO_Speed = GPIO_Speed_100MHz;  
  puerto.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOC, &puerto);
	
}
void inicializar_sensores(void)
{
	GPIO_InitTypeDef puerto;  
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);  
	
	puerto.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1; 
  puerto.GPIO_Mode = GPIO_Mode_IN; 
  puerto.GPIO_PuPd = GPIO_PuPd_NOPULL;   
	
	GPIO_Init(GPIOA, &puerto); 
	
}

// 1estado=1 enciende el led
// estado=0 apadaga el led

void Verde(int estado)
{
	if (estado==1)
		GPIO_SetBits(GPIOC, GPIO_Pin_6);
	else
		GPIO_ResetBits(GPIOC, GPIO_Pin_6);
}
void Rojo(int estado)
{
	if (estado==1)
		GPIO_SetBits(GPIOC, GPIO_Pin_5);
	else
		GPIO_ResetBits(GPIOC, GPIO_Pin_5);
}

uint8_t estadoS0(void) {   
	return !(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)); 
} 
uint8_t estadoS1(void) {   
	return !(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)); 
} 



int main (void)
{
	inicializar_semaforo();
	inicializar_sensores();
	
	// estado inicial en verde
	Verde(1);
	Rojo(0);
	
	while(1)
	{
		if (estadoS0())
		{	Rojo(1); Verde(0); }
		if (estadoS1())
		{
			Rojo(0); Verde(1);
		}
	}
		
	return 0;
}



