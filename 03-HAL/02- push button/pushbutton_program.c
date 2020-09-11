/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 22 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "pushbutton_interface.h"
#include "pushbutton_private.h"
#include "pushbutton_config.h"

#include "GPIO_interface.h"

void PUSHBUTTON_voidInitButton( u8 Copy_u8Port, u8 Copy_u8Pin )
{
	#if PUSHBUTTON_CONNECTION == PULLED_UP
	
		GPIO_voidPinDirection( Copy_u8Port, Copy_u8Pin, INPUT_PULLED );
		GPIO_voidPinValue( Copy_u8Port , Copy_u8Pin , HIGH );
		
	#elif PUSHBUTTON_CONNECTION == PULLED_DOWN
	
		GPIO_voidPinDirection( Copy_u8Port, Copy_u8Pin, INPUT_PULLED );
		GPIO_voidPinValue( Copy_u8Port , Copy_u8Pin , LOW );
	
	#endif
}


u8	 PUSHBUTTON_voidGetButton( u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8DebounceFactor )
{
	u8 Local_u8Result = 0 ;
	u8 Local_u8Loop   = 1 ;
	u8 Local_u8High	  = 0;
	u8 Local_u8Low	  = 0;
	
		while ( Local_u8Loop == 1 )
		{
			if ((GPIO_u8GetPinValue(Copy_u8Port, Copy_u8Pin )))
			{
				Local_u8High ++ ;
				
				if ( Local_u8High >= Copy_u8DebounceFactor )
				{
					#if PUSHBUTTON_CONNECTION == PULLED_UP 
						Local_u8Result = 0;
					#elif PUSHBUTTON_CONNECTION == PULLED_DOWN
						Local_u8Result = 1;
					#endif
					Local_u8Loop   = 0;
					Local_u8High   = 0;
				}
			}
			
			else
			{
				Local_u8Low ++;
				
				if ( Local_u8Low >= Copy_u8DebounceFactor )
				{
					#if PUSHBUTTON_CONNECTION == PULLED_UP 
						Local_u8Result = 1;
					#elif PUSHBUTTON_CONNECTION == PULLED_DOWN
						Local_u8Result = 0;
					#endif
					Local_u8Loop   = 0;
					Local_u8Low    = 0;
				}
			}
		}
	return Local_u8Result ;
}




