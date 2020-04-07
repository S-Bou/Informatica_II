#ifndef __MYCONFIG_H
#define __MYCONFIG_H

#ifdef __cplusplus
extern "C" {
#endif
/*################################### INCLUDES/DEFINES #####################################################*/
#include <stm32f4xx.h> 
#include <stdint.h>
#include <stdio.h>
/*################################### VARIABLES ############################################################*/
/*################################### FUNCTIONS ############################################################*/
void GPIO_Output_Config(void);
void GPIO_Input_Config(void);
void EXT_INT_Config(void);
void DisplayConfig(void);
void Mostrar(uint8_t);
void simul7seg(uint8_t);
void MostrarPulsaciones(uint8_t);
void My_pwm(uint8_t);
/*##########################################################################################################*/
#ifdef __cplusplus
}
#endif

#endif /* __MYCONFIG_H */




