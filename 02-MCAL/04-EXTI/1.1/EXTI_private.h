/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.1                                                              */
/* Date      : 10 september 2020                                                 */
/*********************************************************************************/

#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H


typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_REG;


#define	EXTI  ((volatile EXTI_REG *)0x40010400)

#endif
