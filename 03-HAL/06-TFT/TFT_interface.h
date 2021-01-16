/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 21 September 2020                                                 */
/*********************************************************************************/
#ifndef _TFT_INTERFACE_H
#define _TFT_INTERFACE_H

void TFT_voidInit(void);
void TFT_voidDisplayImage(const u16* Copy_ImagePtr);
void TFT_voidFillColour(u16 Copy_u16Colour);
void TFT_voidDrawRect(u8 x0, u8 x1, u8 y0, u8 y1, u16 copy_u16Color);

#endif
