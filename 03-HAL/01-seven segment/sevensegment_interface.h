/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V01                                                               */
/* Date      : 17 August 2020                                                    */
/*********************************************************************************/
#ifndef _SEVENSEGMENT_INTERFACE_H
#define _SEVENSEGMENT_INTERFACE_H

/****************************/
/*    SEVEN SEGMENT LEDS    */
/*            A             */
/*       ***********        */
/*    F  *         *  B     */ 
/* 	     *    G    *        */
/*	     ***********        */
/*    E  *         *  C     */
/*       *         *        */
/*	     ***********        */
/*            D             */
/****************************/



void SEVENSEGMENT_voidInit(void);
void SEVENSEGMENT_voidDisplayDigit( u8 Copy_u8Character );

#endif
