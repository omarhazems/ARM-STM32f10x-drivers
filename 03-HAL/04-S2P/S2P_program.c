/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 14 September 2020                                                 */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "s2p_interface.h"
#include "s2p_private.h"
#include "s2p_config.h"


void S2P_voidInit()
{
	GPIO_voidPinDirection(SERIAL_PIN, OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(STORAGE_CLK, OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(SHIFT_CLK, OUTPUT_2MHZ_PP);
}

void S2P_voidSendSynchronus(u8 Copy_u8Data)
{
	for (s8 Local_u8Counter = 7; Local_u8Counter >= 0; Local_u8Counter-- )
	{
		u8 Local_u8Bit = GET_BIT(Copy_u8Data, Local_u8Counter);
		GPIO_voidPinValue(SERIAL_PIN, Local_u8Bit);
		GPIO_voidPinValue(SHIFT_CLK, HIGH);
		asm("NOP");
		GPIO_voidPinValue(SHIFT_CLK, LOW);
		asm("NOP");
	}
	
	GPIO_voidPinValue(STORAGE_CLK, HIGH);
	asm("NOP");
	GPIO_voidPinValue(STORAGE_CLK, LOW);
	asm("NOP");
}



