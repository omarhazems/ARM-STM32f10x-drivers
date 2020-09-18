/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 10 september 2020                                                 */
/*********************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

void DMA_voidChannelInit(void);
void DMA_voidChannelStart(u32 * Copy_u32Source_Add_Ptr, u32 * Copy_u32Destination_Add_Ptr, u16 Copy_u16BlockLength );



#endif
