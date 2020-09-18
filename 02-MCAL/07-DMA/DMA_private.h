/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 10 september 2020                                                 */
/*********************************************************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H


typedef struct 
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 RESERVED;
}DMA_Channel;


typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];	
}DMA_t;


#define DMA	((volatile DMA_t *)0x40020000)

#endif
