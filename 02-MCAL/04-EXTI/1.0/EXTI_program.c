/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 22 August 2020                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


static void (*EXTI0_CallBack) (void) = 0 ;



void EXTI_voidSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode)
{
	switch (Copy_u8Mode)
	{
		case RISING:
		SET_BIT(EXTI -> RTSR, EXTI_LINE);
		break;
		
		case FALLING:
		SET_BIT(EXTI -> FTSR, EXTI_LINE);
		break;
		
		case CHANGE:
		SET_BIT(EXTI -> RTSR, EXTI_LINE);
		SET_BIT(EXTI -> FTSR, EXTI_LINE);
		break;
	}
	SET_BIT(EXTI -> IMR, Copy_u8Line);
}

void EXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> IMR, Copy_u8Line);
}


void EXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI -> IMR, Copy_u8Line);
}


void EXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> SWIER, Copy_u8Line);
}

void EXTI_voidSetCallBack(void (*Copy_FuncPtr) (void))
{
	EXTI0_CallBack = Copy_FuncPtr;
}

void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	SET_BIT(EXTI -> PR, 0); /* clears pending bit */
}
