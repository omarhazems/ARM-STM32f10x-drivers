/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 16 September 2020                                                 */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI1_voidSendRecieveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_u8DataToReceive)
{
	/*	CLEAR SLAVE SELECT PIN	*/
	GPIO_voidPinValue(SPI1_SLAVE_PIN, LOW);
	
	/*	SEND DATA	*/
	SPI1 -> DR = Copy_u8DataToTransmit;
	
	/*	WAIT FOR BUSY FLAG	*/
	while (GET_BIT(SPI1 -> SR,7));
	
	/*	RETURN TO THE RECEIVED DATA	*/
	*Copy_u8DataToReceive = SPI1 -> DR ;
	
	/*	SET SLAVE SELECT PIN	*/
	GPIO_voidPinValue(SPI1_SLAVE_PIN, HIGH);
}