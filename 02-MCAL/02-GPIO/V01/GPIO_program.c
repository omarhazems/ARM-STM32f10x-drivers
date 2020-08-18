/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V01                                                               */
/* Date      : 12 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode )
{

	switch(Copy_u8Port)
	{
	case GPIOA :

		if(Copy_u8Pin <= 7 )
		{
			GPIOA_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));
			GPIOA_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}
		else if(Copy_u8Pin <= 15 )
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOA_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOA_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}
		break;

	case GPIOB :

		if(Copy_u8Pin <= 7 )
		{
			GPIOB_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOB_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		else if(Copy_u8Pin <=15 )
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOB_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOB_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
		
	case GPIOC :
		if(Copy_u8Pin <= 7 )
		{
			GPIOC_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOC_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		else if(Copy_u8Pin <=15 )
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOC_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOC_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	}


}

void GPIO_voidPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value )
{

	switch(Copy_u8Port)
	{
	case GPIOA :
		if( u8Copy_u8Value == HIGH )
		{
			SET_BIT( GPIOA_ODR , Copy_u8Pin );
		}
		else if( u8Copy_u8Value == LOW )
		{
			CLR_BIT(  GPIOA_ODR , Copy_u8Pin );
		}
		break;
		
	case GPIOB :
		if( u8Copy_u8Value == HIGH )
		{
			SET_BIT( GPIOB_ODR  , Copy_u8Pin );
		}
		else if( u8Copy_u8Value == LOW )
		{
			CLR_BIT( GPIOB_ODR  , Copy_u8Pin );
		}
		break;
		
	case GPIOC :
		if( u8Copy_u8Value == HIGH )
		{
			SET_BIT( GPIOC_ODR , Copy_u8Pin );
		}
		else if( u8Copy_u8Value == LOW )
		{
			CLR_BIT( GPIOC_ODR , Copy_u8Pin );
		}
		break;
	}

}

u8   GPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin )
{

	u8 Local_u8Result = 0 ;

	switch(Copy_u8Port)
	{
	case GPIOA:
		Local_u8Result = GET_BIT( GPIOA_IDR , Copy_u8Pin );

		break;
	case GPIOB:

		Local_u8Result = GET_BIT( GPIOB_IDR , Copy_u8Pin );

		break;
	case GPIOC:

		Local_u8Result = GET_BIT( GPIOC_IDR , Copy_u8Pin );

		break;
	}
	return Local_u8Result;
}


void GPIO_voidTogglePin( u8 Copy_u8Port , u8 Copy_u8Pin )
{
	switch(Copy_u8Port)
	{
	case GPIOA :
		TOG_BIT( GPIOA_ODR , Copy_u8Pin );
		break;
		
	case GPIOB :
		TOG_BIT( GPIOB_ODR , Copy_u8Pin );
		break;
		
	case GPIOC :
		TOG_BIT( GPIOC_ODR , Copy_u8Pin );
		break;
	}
}

