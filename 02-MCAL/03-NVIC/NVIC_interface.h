//*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 19 August 2020                                                    */
/*********************************************************************************/

#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H







void NVIC_voidInit				(void);
void NVIC_voidEnableInterrupt	( u8 Copy_IntNumber );
void NVIC_voidDisableInterrupt	( u8 Copy_IntNumber );
void NVIC_voidSetPending		( u8 Copy_IntNumber );
u8   NVIC_u8GetActiveFlag		( u8 Copy_IntNumber );
void NVIC_voidSetpriority		( u8 Copy_u8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubGroup, u8 Copy_u8Group );
void NVIC_voidSetPriority( u8 Copy_u8PeripheralIndex, u8 Copy_u8Priority);

#endif