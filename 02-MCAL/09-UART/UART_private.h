/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 19 September 2020                                                 */
/*********************************************************************************/

#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H

typedef struct 
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GRPR;
	
}UART_REG;


#define UART	((volatile UART_REG*)0x40013800)


#endif