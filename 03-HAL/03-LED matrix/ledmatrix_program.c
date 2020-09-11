/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 6 September 2020                                                  */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "ledmatrix_interface.h"
#include "ledmatrix_private.h"
#include "ledmatrix_config.h"


void LEDMRX_voidInit(void)
{
	GPIO_voidPinDirection(LEDMRX_R0,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_R1,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_R2,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_R3,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_R4,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_R5,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_R6,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_R7,OUTPUT_2MHZ_PP);
	
	GPIO_voidPinDirection(LEDMRX_C0,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_C1,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_C2,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_C3,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_C4,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_C5,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_C6,OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(LEDMRX_C7,OUTPUT_2MHZ_PP);
	
}


void LEDMRX_voidDisplay(u8 *Copy_u8Data)
{
	while(1)
	{
		DisableAllColoumns();
		LEDMRX_voidRowValues(Copy_u8Data[0]);
		GPIO_voidPinValue(LEDMRX_C0,LOW);
		STK_voidDelay(2500);
		
		DisableAllColoumns();
		LEDMRX_voidRowValues(Copy_u8Data[1]);
		GPIO_voidPinValue(LEDMRX_C1,LOW);
		STK_voidDelay(2500);
		
		DisableAllColoumns();
		LEDMRX_voidRowValues(Copy_u8Data[2]);
		GPIO_voidPinValue(LEDMRX_C2,LOW);
		STK_voidDelay(2500);
		
		DisableAllColoumns();
		LEDMRX_voidRowValues(Copy_u8Data[3]);
		GPIO_voidPinValue(LEDMRX_C3,LOW);
		STK_voidDelay(2500);
		
		DisableAllColoumns();
		LEDMRX_voidRowValues(Copy_u8Data[4]);
		GPIO_voidPinValue(LEDMRX_C4,LOW);
		STK_voidDelay(2500);
		
		DisableAllColoumns();
		LEDMRX_voidRowValues(Copy_u8Data[5]);
		GPIO_voidPinValue(LEDMRX_C5,LOW);
		STK_voidDelay(2500);
		
		DisableAllColoumns();
		LEDMRX_voidRowValues(Copy_u8Data[6]);
		GPIO_voidPinValue(LEDMRX_C6,LOW);
		STK_voidDelay(2500);
		
		DisableAllColoumns();
		LEDMRX_voidRowValues(Copy_u8Data[7]);
		GPIO_voidPinValue(LEDMRX_C7,LOW);
		STK_voidDelay(2500);
	}
}

static void DisableAllColoumns(void)
{
	GPIO_voidPinValue(LEDMRX_C0,HIGH);
	GPIO_voidPinValue(LEDMRX_C1,HIGH);
	GPIO_voidPinValue(LEDMRX_C2,HIGH);
	GPIO_voidPinValue(LEDMRX_C3,HIGH);
	GPIO_voidPinValue(LEDMRX_C4,HIGH);
	GPIO_voidPinValue(LEDMRX_C5,HIGH);
	GPIO_voidPinValue(LEDMRX_C6,HIGH);
	GPIO_voidPinValue(LEDMRX_C7,HIGH);
}

static void LEDMRX_voidRowValues(u8 Copy_u8Value)
{
	u8 Local_u8Bit = 0;

	Local_u8Bit = GET_BIT(Copy_u8Value,0);
	GPIO_voidPinValue(LEDMRX_R0,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,1);
	GPIO_voidPinValue(LEDMRX_R1,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,2);
	GPIO_voidPinValue(LEDMRX_R2,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,3);
	GPIO_voidPinValue(LEDMRX_R3,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,4);
	GPIO_voidPinValue(LEDMRX_R4,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,5);
	GPIO_voidPinValue(LEDMRX_R5,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,6);
	GPIO_voidPinValue(LEDMRX_R6,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,7);
	GPIO_voidPinValue(LEDMRX_R7,Local_u8Bit);
}
