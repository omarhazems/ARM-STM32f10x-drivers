/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 16 September 2020                                                 */
/*********************************************************************************/
#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H

void SPI1_voidInit(void);
void SPI1_voidSendRecieveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_u8DataToReceive);
void SPI1_voidSendRecieveAsynch(u8 Copy_u8DataToTransmit, u8 *Copy_u8DataToReceive, void (*CallBack) (void));


#endif
