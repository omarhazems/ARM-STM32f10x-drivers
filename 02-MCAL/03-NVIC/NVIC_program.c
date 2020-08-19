/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 19 August 2020                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void NVIC_voidEnableInterrupt( u8 Copy_IntNumber )
{
	if ( Copy_IntNumber <= 31 )
	{
		NVIC_ISER0 = (1 << Copy_IntNumber);
	}
	else if ( Copy_IntNumber <= 59 )
	{
		Copy_IntNumber -= 32 ;
		NVIC_ISER1 = (1 << Copy_IntNumber);
	}
	else 
	{
		/* RETURN ERROR */
	}
}


void NVIC_voidSetPending( u8 Copy_IntNumber )
{
	if ( Copy_IntNumber <= 31 )
	{
		NVIC_ICER0 = (1 << Copy_IntNumber);
	}
	else if ( Copy_IntNumber <= 59 )
	{
		Copy_IntNumber -= 32 ;
		NVIC_ICER1 = (1 << Copy_IntNumber);
	}
	else 
	{
		/* RETURN ERROR */
	}
}

void NVIC_voidDisableInterrupt( u8 Copy_IntNumber )
{
	if ( Copy_IntNumber <= 31 )
	{
		NVIC_ISPR0 = (1 << Copy_IntNumber);
	}
	else if ( Copy_IntNumber <= 59 )
	{
		Copy_IntNumber -= 32 ;
		NVIC_ISPR1 = (1 << Copy_IntNumber);
	}
	else 
	{
		/* RETURN ERROR */
	}
}

void NVIC_voidClearPending( u8 Copy_IntNumber )
{
	if ( Copy_IntNumber <= 31 )
	{
		NVIC_ICPR0 = (1 << Copy_IntNumber);
	}
	else if ( Copy_IntNumber <= 59 )
	{
		Copy_IntNumber -= 32 ;
		NVIC_ICPR1 = (1 << Copy_IntNumber);
	}
	else 
	{
		/* RETURN ERROR */
	}
}

u8   NVIC_u8GetActiveFlag ( u8 Copy_IntNumber)
{
		u8 Local_u8Result = 0;
		
	if ( Copy_IntNumber <= 31 )
	{
		Local_u8Result = GET_BIT( NVIC_IABR0, Copy_IntNumber);
	}
	else if ( Copy_IntNumber <= 59 )
	{
		Copy_IntNumber -= 32 ;
		Local_u8Result = GET_BIT( NVIC_IABR1, Copy_IntNumber);
	}
	else 
	{
		/* RETURN ERROR */
	}
	return Local_u8Result ;
}



