//*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 19 August 2020                                                    */
/*********************************************************************************/

#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H








void NVIC_voidEnableInterrupt( u8 Copy_IntNumber );
void NVIC_voidDisableInterrupt( u8 Copy_IntNumber );
void NVIC_voidSetPending( u8 Copy_IntNumber );
u8   NVIC_u8GetActiveFlag ( u8 Copy_IntNumber);




#endif