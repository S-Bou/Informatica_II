#include <stdint.h>
#include <stm32f4xx.h> 
#include <stm32f4xx_gpio.h> 
#include <stm32f4xx_rcc.h> 

uint8_t cara = 1;            //    ccc-cccc 
uint8_t figuras[6] = {
											0x08,  //1 - 000-   1000  
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
	GPIO_Init(GPIOA, &puerto); 
} 
	
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


int main(void) {
		
		int r;
	int j;
	led_conf();
  iniciarPulsador(); 
	r=0;
	
	while(1){
	
		if (estadoPulsador()) {
											       r=(r+1)%5;
														 for (j=0;j<2000000;j++) {};
														 while(estadoPulsador());
														 for (j=0;j<2000000;j++) {};
														  
		}
		led_on();
		for (j=0;j<1000000+2000000*r;j++) {};
		led_off();
		for (j=0;j<1000000+2000000*r;j++) {};		
	}
		return(0); 
}




//	int j;
//	led_conf();

//	while(1)
//{
//		led_on();
//		for (j=0;j<10000000;j++) {};
//		led_off();
//		for (j=0;j<10000000;j++) {};
//}