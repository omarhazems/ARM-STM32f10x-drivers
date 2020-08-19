/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 19 August 2020                                                    */
/*********************************************************************************/

#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H


/* BASE ADDRESS	0xE000E100  */

#define	NVIC_ISER0	*((u32*)0xE000E100)	/* ENABLE EXTERNAL INTERRUPTS FROM 0  TO 31 */
#define	NVIC_ISER1	*((u32*)0xE000E104) /* ENABLE EXTERNAL INTERRUPTS FROM 32 TO 64 */

#define	NVIC_ICER0	*((u32*)0xE000E180)	/* DISABLE EXTERNAL INTERRUPTS FROM 0  TO 31 */
#define	NVIC_ICER1	*((u32*)0xE000E184) /* DISABLE EXTERNAL INTERRUPTS FROM 32 TO 64 */


#define	NVIC_ISPR0	*((u32*)0xE000E200)	/* SET PENDING FOR EXTERNAL INTERRUPTS FROM 0  TO 31 */
#define	NVIC_ISPR1	*((u32*)0xE000E204) /* SET PENDING FOR EXTERNAL INTERRUPTS FROM 32 TO 64 */

#define	NVIC_ICPR0	*((u32*)0xE000E280)	/* CLEAR PENDING FOR EXTERNAL INTERRUPTS FROM 0  TO 31 */
#define	NVIC_ICPR1	*((u32*)0xE000E284) /* CLEAR PENDING FOR EXTERNAL INTERRUPTS FROM 32 TO 64 */

#define	NVIC_IABR0	*((volatile u32*)0xE000E300)	/* GET ACTIVE BIT VALUE FOR EXTERNAL INTERRUPTS FROM 0  TO 31 */
#define	NVIC_IABR1	*((volatile u32*)0xE000E304) 	/* GET ACTIVE BIT VALUE FOR EXTERNAL INTERRUPTS FROM 32 TO 64 */




#endif