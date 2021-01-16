/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 28 September 2020                                                 */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"


void ESP_INIT(void)
{
	u8 Local_u8Result = 0;
	
	while (Local_u8Result == 0)
	{
		/* stop ECHO */
		USART1_voidTransmit("ATE0\r\n");
		Local_u8Result = voidESPValidateCmd();
	}
	
	Local_u8Result == 0
	
	while(Local_u8Result == 0)
	{
		/* Set station mode */
		USART1_voidTransmit("AT+CWMODE=1\r\n");
		Local_u8Result = voidESPValidateCmd();
	}
}



static u8 voidESPValidateCmd(void)
{
	u8 Local_u8Response[100] = {0};
	
	while()
	{
		Local_u8Response[] = USART_voidReceive()
	}
	
}