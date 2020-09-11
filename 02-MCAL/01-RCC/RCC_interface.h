/*****************************************************************************************/
/*Author    : Omar Hazem																 */
/*Version   : V1.0																		 */
/* Date     : 8 August 2020 															 */
/*****************************************************************************************/
#ifndef _RCC_interface_H
#define _RCC_interface_H

/*  peripheral definitions	*/
#define	RCC_AHB		0
#define	RCC_APB1	1
#define	RCC_APB2	2

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);


#endif
