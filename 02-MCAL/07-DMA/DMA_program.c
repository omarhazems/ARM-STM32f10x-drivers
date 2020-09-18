/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 10 september 2020                                                 */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"



void DMA_voidChannelInit(void)
{
	#if(CHANNEL_ID == 1)
		DMA -> Channel[0].CCR = ;
}


void DMA_voidChannelStart(u32 * Copy_u32Source_Add_Ptr, u32 * Copy_u32Destination_Add_Ptr, u16 Copy_u16BlockLength )
{
	CLR_BIT(DMA -> Channel[0].CCR, 0);
	DMA -> Channel[0].CPAR = Copy_u32Source_Add_Ptr;
	DMA -> Channel[0].CMAR = Copy_u32Destination_Add_Ptr;
	
	DMA -> Channel[0].CNDTR = Copy_u16BlockLength;
	
	SET_BIT(DMA -> Channel[0].CCR , 0);
}

