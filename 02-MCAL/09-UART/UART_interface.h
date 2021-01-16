/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 19 September 2020                                                 */
/*********************************************************************************/

#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H


void UART1_voidInit();
void UART1_voidTransmit(u8 arr[]);
u8 	 UART1_u8Recieve(void);

#endif
