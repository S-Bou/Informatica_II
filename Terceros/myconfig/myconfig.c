/*################################### INCLUDES/DEFINES #####################################################*/
#include "myconfig.h"
/*################################### VARIABLES ############################################################*/
uint8_t tabla[11] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x18, 0x06};
uint8_t pulsaciones = 0;
/*################################### DESCRIPTION/CONECTIONS ###############################################*/
/*
	1. Config pins as exit for leds.
		 GPIO_Pin_12 -> Green led
		 GPIO_Pin_13 -> Orange led
		 GPIO_Pin_14 -> Red led
		 GPIO_Pin_15 -> Blue led
	2. Config pins as input, example:
		 Button user to PA0 defined as GPIO_EXTI0.
	   For know state of it use: GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0); 
	3. Config external interrupt in a user button (PA0).
	4. Config pins for display in practice 6
	5. Call function 6 in practice 6
	6. Simulate exit in display in practice 6
	7. Show number of pulsations in practice 7
	8.
	9.
*/
/*################################### FUNCTION 1 ###########################################################*/
void GPIO_Output_Config(void) //configura apropiadamente la GPIO
{
	/*Configure GPIO pins: GreenLed_Pin OrangeLed_Pin RedLed_Pin BlueLed_Pin */
	GPIO_InitTypeDef puerto;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);  
	puerto.GPIO_Pin   = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	puerto.GPIO_Mode  = GPIO_Mode_OUT;
	puerto.GPIO_OType = GPIO_OType_PP; 
	puerto.GPIO_Speed = GPIO_Speed_100MHz;  
	puerto.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &puerto);	
	/*Configure GPIO pin Output Level as RESET, use GPIO_SetBits() for init as SET*/
  GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
}
/*################################### FUNCTION 2 ###########################################################*/
void GPIO_Input_Config(void)  //Botón azul PA0
{
	GPIO_InitTypeDef puerto;
	/* Enable GPIOA clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  
	
	puerto.GPIO_Pin  = GPIO_Pin_0; 
	puerto.GPIO_Mode = GPIO_Mode_IN; 
	puerto.GPIO_PuPd = GPIO_PuPd_NOPULL;   
	GPIO_Init(GPIOA, &puerto); 
} 
/*################################### FUNCTION 3 ###########################################################*/
void EXT_INT_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	/* Connect EXTI Line0 to PA0 pin */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
	/* Configure EXTI Line0 */
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising; 
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set EXTI Line0 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
/*################################### FUNCTION 4 ###########################################################*/
void DisplayConfig(void)
{
        GPIO_InitTypeDef puerto;
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
        puerto.GPIO_Pin   = 0x005F;;
        puerto.GPIO_Mode  = GPIO_Mode_OUT;
        puerto.GPIO_OType = GPIO_OType_OD;
        puerto.GPIO_Speed = GPIO_Speed_2MHz;
        puerto.GPIO_PuPd  = GPIO_PuPd_UP;
        GPIO_Init(GPIOD, &puerto);
}
/*################################### FUNCTION 5 ###########################################################*/
void Mostrar(uint8_t piso)
{
        uint8_t resultado;
        resultado = tabla[piso];
        simul7seg(resultado);
}
/*################################### FUNCTION 6 ###########################################################*/
void simul7seg(uint8_t valor)
{

switch (valor){
case 0x40:
  printf("0");
  break;
case 0x79:
  printf("1");
  break;
case 0x24:
  printf("2");
  break;
case 0x30:
  printf("3");
  break;
case 0x19:
  printf("4");
  break;
case 0x12:
  printf("5");
  break;
case 0x02:
  printf("6");
  break;
case 0x78:
  printf("7");
  break;
case 0x00:
  printf("8");
  break;
case 0x18:
  printf("9");
  break;
case 0x06:
  printf("E");
  break;
default:
  printf("Error");
  break;
}

}
/*################################### FUNCTION 7 ###########################################################*/
void MostrarPulsaciones(uint8_t pulse)
{
	printf("Numero de pulsaciones: %d\n", pulsaciones);
}
/*################################### FUNCTION 8 ###########################################################*/

/*################################### FUNCTION 9 ###########################################################*/

/*################################### FUNCTION 10 ##########################################################*/

/*################################### FUNCTION 11 ##########################################################*/

/*################################### FUNCTION 12 ##########################################################*/

/*################################### FUNCTION 13 ##########################################################*/

/*################################### FUNCTION 14 ##########################################################*/


