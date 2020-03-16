#include <stdint.h>
#include <stm32f4xx.h> 
#include <stm32f4xx_gpio.h> 
#include <stm32f4xx_rcc.h> 

#include <stdio.h>


#include <stdio.h>
#include <stm32f4xx.h>


uint8_t cara = 1;            //    ccc-cccc 
uint8_t figuras[6] = {0x08,  //1 - 000-   1000  
											0x11,  //2 - 001-   0001  
											0x19,  //3 - 001-   1001
											0x55,  //4 - 101-   0101
											0x5D,  //5 - 101-   1101
											0x77,  //6 - 111-   0111 
	}; 
	void iniciarPulsador(void) 
{
	GPIO_InitTypeDef puerto;   
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  
	puerto.GPIO_Pin  = GPIO_Pin_0; 
  puerto.GPIO_Mode = GPIO_Mode_IN; 
  puerto.GPIO_PuPd = GPIO_PuPd_NOPULL;   
	GPIO_Init(GPIOA, &puerto); } 

	
void led_conf(void) //configura apropiadamente la GPIO o
{
		GPIO_InitTypeDef puerto;
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);  
		puerto.GPIO_Pin   = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
		puerto.GPIO_Mode  = GPIO_Mode_OUT;
	  puerto.GPIO_OType = GPIO_OType_PP; 
    puerto.GPIO_Speed = GPIO_Speed_100MHz;  
   	puerto.GPIO_PuPd  = GPIO_PuPd_NOPULL;
   	GPIO_Init(GPIOD, &puerto);
	
}

void led_on(void)  //enciende el led naranja o
{
 GPIO_SetBits(GPIOD, GPIO_Pin_12);
}
void led_off(void) //apaga el led naranja 
{
 GPIO_ResetBits(GPIOD, GPIO_Pin_12);
}
	

uint8_t estadoPulsador(void) {   
	
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0); 
} 

void visualizarDado(uint8_t c) 
{
   GPIO_Write(GPIOD, figuras[c - 1]); 
} 


void Configurar_Interrupcion()
{
	// configurar el pin como entrada digital
	GPIO_InitTypeDef cucaracha;   
	NVIC_InitTypeDef eltipoypindeinterrupcion;
	EXTI_InitTypeDef EXTI_InitStructure;
	
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  
	cucaracha.GPIO_Pin  = GPIO_Pin_0; 
	cucaracha.GPIO_Mode = GPIO_Mode_IN; 
  cucaracha.GPIO_PuPd = GPIO_PuPd_NOPULL;   
	
	GPIO_Init(GPIOA, &cucaracha); 
	
	// activo el reloj para acceder al dispositivo SYSCFG
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE); /* Enable SYSCFG clock */ 

	// configurar la linea 0 como interrupcion
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	// la interrupcion previa le damos una prioridad.
	eltipoypindeinterrupcion.NVIC_IRQChannel = EXTI0_IRQn;
	eltipoypindeinterrupcion.NVIC_IRQChannelPreemptionPriority = 0x00;
	eltipoypindeinterrupcion.NVIC_IRQChannelSubPriority = 0x00;
	eltipoypindeinterrupcion.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&eltipoypindeinterrupcion);

} 

volatile uint32_t msTicks;
extern int numero_de_pulsaciones;

void Configurar_Interrupcion_Temporizador(int valueus)
{
	// cada cuanto se desea interrupciones 1000 -> seria cada 1ms
 SystemCoreClockUpdate();
 if(SysTick_Config(SystemCoreClock / valueus))
 {
 while(1);
 }
}

void Delay(uint32_t dlyTicks)
{
 uint32_t curTicks;
 curTicks = msTicks;
 while((msTicks - curTicks) < dlyTicks);
}


void delay_mediosegundo_1()
{
	while (msTicks<500);
	msTicks=0;
}

void delay_mediosegundo_2()
{
	while ((msTicks%500)==0);
}

void delay_mediosegundo()
{
	int temp;
	
	temp=msTicks;
	while ((msTicks-temp)<500);
	
}

void delay_s(int num_segundos)
{
	int temp;
	temp=msTicks;
	while((msTicks-temp)<(num_segundos*1000));
	
}

void delay_ms(int num_msegundos)
{
	int temp;
	temp=msTicks;
	while((msTicks-temp)<(num_msegundos));
	
}


int main(void) {
	
	Configurar_Interrupcion();
	Configurar_Interrupcion_Temporizador(1000);
		
	while(1){
		
		delay_ms(100);
		printf("El numero de pulsaciones es: %d %d s %d pul/min %d pul/seg\r\n",numero_de_pulsaciones, msTicks/1000,numero_de_pulsaciones/(msTicks/1000)*60,numero_de_pulsaciones/(msTicks/1000));
		//printf("Valor de la variable msTicks: %d \r\n",msTicks);
		//Delay(100);
		
		};
	return(0); 
}

