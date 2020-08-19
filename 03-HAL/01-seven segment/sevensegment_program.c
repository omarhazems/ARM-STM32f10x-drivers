/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 17 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "sevensegment_interface.h"
#include "sevensegment_private.h"
#include "sevensegment_config.h"

#include "GPIO_interface.h"

void NOP_voidDelay(void);


void SEVENSEGMENT_voidInit(void)
{	
	#if SEVENSEGMENT_TYPE	==	COMMON_CATHODE

	/*	SET ALL PINS USED FOR SEVEN SEGMENT TO OUTPUT, 2MHZ SPEED, PUSH-PULL MODE	*/
		GPIO_voidPinDirection(SEVENSEGMENT_PORT , SSA , OUTPUT_2MHZ_PP);
		GPIO_voidPinDirection(SEVENSEGMENT_PORT , SSB , OUTPUT_2MHZ_PP);
		GPIO_voidPinDirection(SEVENSEGMENT_PORT , SSC , OUTPUT_2MHZ_PP);
		GPIO_voidPinDirection(SEVENSEGMENT_PORT , SSD , OUTPUT_2MHZ_PP);
		GPIO_voidPinDirection(SEVENSEGMENT_PORT , SSE , OUTPUT_2MHZ_PP);
		GPIO_voidPinDirection(SEVENSEGMENT_PORT , SSF , OUTPUT_2MHZ_PP);
		GPIO_voidPinDirection(SEVENSEGMENT_PORT , SSG , OUTPUT_2MHZ_PP);
		GPIO_voidPinDirection(SEVENSEGMENT_PORT , SSDOT , OUTPUT_2MHZ_PP);

			/*	TEST SEVEN SEGMENT LEDS FOR ONE SECOND */	
		#if	SEVENSEGMENT_PORT	==	GPIOA

			#define	REGISTER	*((u32*)(0x40010800 + 0x0c))

		#elif	SEVENSEGMENT_PORT	==	GPIOB

			#define	REGISTER	*((u32*)(0x40010C00 + 0x0c))

		#endif

		
	#elif	SEVENSEGMENT_TYPE	==	COMMON_ANODE
		/*	COMMON ANODE SEVEN SEGMENT CODE HERE	*/
	#endif
		REGISTER |=  ((1<<SSA) | (1<<SSB) | (1<<SSC) | (1<<SSD) | (1<<SSE) | (1<<SSF) | (1<<SSG) | (1<<SSDOT));
		NOP_voidDelay();
		REGISTER &= ~ ((1<<SSA) | (1<<SSB) | (1<<SSC) | (1<<SSD) | (1<<SSE) | (1<<SSF) | (1<<SSG) | (1<<SSDOT));
}


void SEVENSEGMENT_voidDisplayDigit( u8 Copy_u8Character )
{
	REGISTER &= ~ ((1<<SSA) | (1<<SSB) | (1<<SSC) | (1<<SSD) | (1<<SSE) | (1<<SSF) | (1<<SSG) | (1<<SSDOT));
	
	switch (Copy_u8Character)
	{
		case 0 :
		REGISTER |= ( (1<<SSA) | (1<<SSB) | (1<<SSC) | (1<<SSD) | (1<<SSE) | (1<<SSF) );
		break;
		
		case 1 :
		REGISTER |= ( (1<<SSB) | (1<<SSC) );
		break;
		
		case 2 :
		REGISTER |= ( (1<<SSA) | (1<<SSB) | (1<<SSG) | (1<<SSE) | (1<<SSD) );
		break;
		
		case 3 :
		REGISTER |= ( (1<<SSA) | (1<<SSB) | (1<<SSC) | (1<<SSD) | (1<<SSG) );
		break;
		
		case 4 :
		REGISTER |= ( (1<<SSB) | (1<<SSC) | (1<<SSF) | (1<<SSG) );	
		break;
		
		case 5 :
		REGISTER |= ( (1<<SSA) | (1<<SSC) | (1<<SSD) | (1<<SSF) | (1<<SSG) );
		break;
		
		case 6 :
		REGISTER |= ( (1<<SSA) | (1<<SSC) | (1<<SSD) | (1<<SSE) | (1<<SSF) | (1<<SSG) );
		break;
		
		case 7 :
		REGISTER |= ( (1<<SSA) | (1<<SSB) | (1<<SSC) );
		break;
		
		case 8 :
		REGISTER |= ( (1<<SSA) | (1<<SSB) | (1<<SSC) | (1<<SSD) | (1<<SSE) | (1<<SSF) | (1<<SSG) );
		break;
		
		case 9 :
		REGISTER |= ( (1<<SSA) | (1<<SSB) | (1<<SSC) | (1<<SSD) | (1<<SSF) | (1<<SSG) );
		break;
		
	}
}

void NOP_voidDelay(void)
{
	for (int i = 0 ; i < 1000 ; i++)
	{
		for (int j = 0 ; j < 1000 ; j++)
		{
			asm("NOP");
		}
	}
}
