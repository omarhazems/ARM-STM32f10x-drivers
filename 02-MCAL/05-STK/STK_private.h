/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 1 September 2020                                                  */
/*********************************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_AHB		0
#define	STK_AHB_8	1

#define	STK_BASE_ADDRESS	 0xE000E010

#define	STK_CTRL	*((volatile u32*)((STK_BASE_ADDRESS)+0x00))
#define	STK_LOAD	*((volatile u32*)((STK_BASE_ADDRESS)+0x04))
#define	STK_VAL		*((volatile u32*)((STK_BASE_ADDRESS)+0x08))


#endif