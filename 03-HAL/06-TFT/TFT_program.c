/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 21 September 2020                                                 */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"



void TFT_voidInit(void)
{
	/*	RESET PULSE	*/
	GPIO_voidPinValue(TFT_RST_PIN, HIGH);
	STK_voidDelay(100);
	GPIO_voidPinValue(TFT_RST_PIN, LOW);
	STK_voidDelay(1);
	GPIO_voidPinValue(TFT_RST_PIN, HIGH);
	STK_voidDelay(100);
	GPIO_voidPinValue(TFT_RST_PIN, LOW);
	STK_voidDelay(100);
	GPIO_voidPinValue(TFT_RST_PIN, HIGH);
	STK_voidDelay(120000);
	
	/*	SLEEP OUT COMMAND */
	voidSendCommand(0x11);
	STK_voidDelay(150000);
	voidSendCommand(0x3A);
	voidSendData(0x05);
	
	/*	DISPLAY ON COMMAND	*/
	voidSendCommand(0x29);
}



void TFT_voidDisplayImage(const u16* Copy_Image)
{
	u16 counter;
	u8 Data;

	/*	SET X ADDRESS	*/
	voidSendCommand(0x2A);
	/*	START POINTS	*/
	voidSendData(0);
	voidSendData(0);
	/*	END POINTS		*/
	voidSendData(0);
	voidSendData(127);

	/*	SET Y ADDRESS	*/
	voidSendCommand(0x2B);
	/*	START POINTS	*/
	voidSendData(0);
	voidSendData(0);
	/*	END POINTS		*/
	voidSendData(0);
	voidSendData(159);

	/*	RAM WRITE COMMAND	*/
	voidSendCommand(0x2C);
	for(counter = 0 ; counter < 20480 ; counter ++)
	{
		Data = Copy_Image[counter] >> 8;

		/* Write the high byte */
		voidSendData(Data);
		/* Write the low byte */
		Data = Copy_Image[counter] & 0x00ff;
		voidSendData(Data);
	}
}



void TFT_voidFillColour(u16 Copy_u16Colour)
{
	u16 counter;
	u8 Data;

	/*	SET X ADDRESS	*/
	voidSendCommand(0x2A);
	/*	START POINTS	*/
	voidSendData(0);
	voidSendData(0);
	/*	END POINTS		*/
	voidSendData(0);
	voidSendData(127);

	/*	SET Y ADDRESS	*/
	voidSendCommand(0x2B);
	/*	START POINTS	*/
	voidSendData(0);
	voidSendData(0);
	/*	END POINTS		*/
	voidSendData(0);
	voidSendData(159);

	/*	RAM WRITE COMMAND	*/
	voidSendCommand(0x2C);
	for(counter = 0 ; counter < 20480 ; counter ++)
	{
		Data = Copy_u16Colour >> 8;

		/* Write the high byte */
		voidSendData(Data);
		/* Write the low byte */
		Data = Copy_u16Colour & 0x00ff;
		voidSendData(Data);
	}
}



void TFT_voidDrawRect(u8 x0, u8 x1, u8 y0, u8 y1, u16 copy_u16Color)
{
	u16 counter;
	u8 Data;
	u16 size = (x1-x0)*(y1-y0);
	
	/*	SET X ADDRESS	*/
	voidSendCommand(0x2A);
	/*	START POINTS	*/
	voidSendData(0);
	voidSendData(x0);

	/*	END POINTS		*/
	voidSendData(0);
	voidSendData(x1);

	/*	SET Y ADDRESS	*/
	voidSendCommand(0x2B);
	/*	START POINTS	*/
	voidSendData(0);
	voidSendData(y0);
	/*	END POINTS		*/
	voidSendData(0);
	voidSendData(y1);

	/*	RAM WRITE COMMAND	*/
	voidSendCommand(0x2C);
	for(counter = 0 ; counter < size ; counter ++)
	{
		Data = Copy_u16Colour >> 8;

		/* Write the high byte */
		voidSendData(Data);
		/* Write the low byte */
		Data = Copy_u16Colour & 0x00ff;
		voidSendData(Data);
	}
}


static void voidSendCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	/*	SET PIN A0	LOW	*/
	GPIO_voidPinValue(TFT_A0_PIN,LOW);
	
	/*	SEND COMMAND OVER SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Command, &Local_u8Temp);
}


static void voidSendData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;
	/*	SET PIN A0	HIGH	*/
	GPIO_voidPinValue(TFT_A0_PIN,HIGH);
	
	
	/*	SEND COMMAND OVER SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Data, &Local_u8Temp);
	
}
