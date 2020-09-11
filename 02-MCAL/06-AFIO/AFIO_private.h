/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 10 september 2020                                                 */
/*********************************************************************************/

#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H



typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;
	volatile u32 MAPR2;
	
}AFIO_REG;

#define AFIO	((volatile AFIO_REG*)0x40010000)

#endif
