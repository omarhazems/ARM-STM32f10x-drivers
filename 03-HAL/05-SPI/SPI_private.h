/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 16 September 2020                                                 */
/*********************************************************************************/
#ifndef _SPI_PRIVATE_H
#define _SPI_PRIVATE_H


typedef	struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRC;
	volatile u32 TXCRC;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
	
}SPI_REGISTERS;

#define	SPI1		((SPI_REGISTERS*)0x40013000)

#endif