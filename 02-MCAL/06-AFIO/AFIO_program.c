/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 10 september 2020                                                 */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


void AFIO_voidEnableEXTI(u8 Copy_u8Line, u8 Copyu8Port)
{
	if (Copy_u8Line < 4)
	{
		u8 Local_u8Shift = (4*Copy_u8Line);
		(AFIO -> EXTICR1) |= (Copyu8Port << Local_u8Shift);
	}
	else if (Copy_u8Line < 8)
	{
		u8 Local_u8Shift = (4*(Copy_u8Line-4));
		(AFIO -> EXTICR2) |= (Copyu8Port << Local_u8Shift);
	}
	else if (Copy_u8Line < 12)
	{
		u8 Local_u8Shift = (4*(Copy_u8Line-8));
		(AFIO -> EXTICR3) |= (Copyu8Port << Local_u8Shift);
	}
	else if (Copy_u8Line < 16)
	{
		u8 Local_u8Shift = (4*(Copy_u8Line-12));
		(AFIO -> EXTICR4) |= (Copyu8Port << Local_u8Shift);	
	
	}
	else 
	{
		/*	ERROR : LINE DOESN'T ESXIST  */
	}
}