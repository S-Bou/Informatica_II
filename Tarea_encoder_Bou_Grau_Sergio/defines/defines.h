/**
 *  Defines for your entire project at one place
 * 
 *	@author 	Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@version 	v1.0
 *	@ide		Keil uVision 5
 *	@license	GNU GPL v3
 *	
 * |----------------------------------------------------------------------
 * | Copyright (C) Tilen Majerle, 2014
 * | 
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |  
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * | 
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |----------------------------------------------------------------------
 */
#ifndef TM_DEFINES_H
#define TM_DEFINES_H

/* Put your global defines for all libraries here used in your project */
#define STM32F401xx
//Change X with possible U(S)ARTs: USART1, USART2, USART3, UART4, UART5, USART6, UART7, UART8
//Set flow control
#define TM_1_HARDWARE_FLOW_CONTROL		TM_USART_HardwareFlowControl_None
//Set mode
#define TM_1_MODE						USART_Mode_Tx | USART_Mode_Rx
//Set parity
#define TM_1_PARITY						USART_Parity_No
//Set stopbits
#define TM_1_STOP_BITS					USART_StopBits_1
//Set USART datasize
#define TM_1_WORD_LENGTH				USART_WordLength_8b

#endif
