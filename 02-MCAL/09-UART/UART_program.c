/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 19 September 2020                                                 */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART1_voidInit()
{
	UART_REG -> BRR = 0x341; /*	9600 baudrate */
	SET_BIT(UART_REG -> CR1, 2); /*ENABLE Rx */
	SET_BIT(UART_REG -> CR1, 3); /* ENABLE Tx */
	SET_BIT(UART_REG -> CR1, 13); /* ENABLE UART */
	UART_REG -> SR = 0; /* clear status registers */
}

void UART1_voidTransmit(u8 arr[])
{
	u8 i = 0;
	while (arr[i] != '\0')
	{
		UART_REG -> DR = arr[i];
		while (((UART_REG -> SR) & 0x40) ==  0);
		i++;
	}
	
}


u8 	 UART1_u8Recieve(void)
{
	while (((UART_REG -> SR) & (1<< 5)) == 0);
	return (0xFF & (UART_REG -> DR));
	
	
}