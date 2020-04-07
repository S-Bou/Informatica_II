
#include <stm32f4xx_gpio.h> 
#include <stm32f4xx_rcc.h> 
#include <stm32f4xx.h>
#include <stdio.h>
#include <stdint.h>

/* Include my libraries here */
#include "defines.h"
#include "tm_stm32f4_usart.h"

/*·Function prototipes·-------------------------------------------------------------*/
void EXT_INT_Config_PA0(void);
void Delay_ms(uint32_t data);

/*·Global variables·----------------------------------------------------------------*/
volatile uint32_t ContadorPinA0 = 0;
extern volatile uint32_t timeTicks;

/*----------------------------------------------------------------------------------*/
int main(void) {
	
	char buf_tmp[250];
	char c;
  int cuenta;
	
	SysTick_Config(8000000*0.001);
	
	EXT_INT_Config_PA0();
	
	/* Initialize USART1 at 9600 baud, TX: P16, RX: PB7 */
	TM_USART_Init(USART1, TM_USART_PinsPack_1, 9600);
  
//    cuenta=1000;  
    /* Put string to USART */
//		sprintf(buf_tmp,"Hola esto es una prueba %d \r\n", cuenta);
//    TM_USART_Puts(USART1, "Hello world\n\r");
//    TM_USART_Puts(USART1, buf_tmp);
	
while (1) {
        /* Get character from internal buffer */
        c = TM_USART_Getc(USART1);
        if (c) {
            /* If anything received, put it back to terminal */
            TM_USART_Putc(USART1, c);
        }
				
		sprintf(buf_tmp,"Numero de pulsos del encoder: %d \r\n\n",ContadorPinA0);
    TM_USART_Puts(USART1, buf_tmp);
		Delay_ms(500);
}	
}
/*·Function definitions·-------------------------------------------------------------*/
void EXT_INT_Config_PA0(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	/*Connect EXTI Line0 to PA0 pin*/
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
	/*Configure EXTI Line0*/
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	/*Enable and set EXTI Line0 interrupt to the lowest priority*/
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void Delay_ms(uint32_t data) 
{
	timeTicks = 0;
	
	while(timeTicks <= data){}

}


