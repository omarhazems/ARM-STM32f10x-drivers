/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 22 August 2020                                                    */
/*********************************************************************************/
#ifndef _PUSHBUTTON_INTERFACE_H
#define _PUSHBUTTON_INTERFACE_H


void PUSHBUTTON_voidInitButton	(u8 Copy_u8Port, u8 Copy_Pin);
u8	 PUSHBUTTON_voidGetButton	(u8 Copy_u8Port, u8 Copy_Pin, u8 Copy_u8DebounceFactor );

#endif
