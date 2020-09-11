/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.1                                                              */
/* Date      : 10 september 2020                                                 */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#include "GPIO_interface.h"
#include "AFIO_interface.h"

static void (*EXTI0_CallBack) (void) = 0 ;
static void (*EXTI1_CallBack) (void) = 0 ;
static void (*EXTI2_CallBack) (void) = 0 ;
static void (*EXTI3_CallBack) (void) = 0 ;
static void (*EXTI4_CallBack) (void) = 0 ;
static void (*EXTI9_5_CallBack) (void) = 0 ;
static void (*EXTI15_10_CallBack) (void) = 0 ;




void EXTI_voidSetEXTI(u8 Copy_u8Line, u8 Copyu8Port, u8 Copy_u8Mode)
{
	/*	chooses mode of interrupt  */
	switch (Copy_u8Mode)
	{
		case RISING:
		GPIO_voidPinDirection(Copyu8Port, Copy_u8Line, INPUT_PULLED);
		GPIO_voidPinValue(Copyu8Port, Copy_u8Line, LOW);
		SET_BIT(EXTI -> RTSR, Copy_u8Line);
		break;
		
		case FALLING:
		GPIO_voidPinDirection(Copyu8Port, Copy_u8Line, INPUT_PULLED);
		GPIO_voidPinValue(Copyu8Port, Copy_u8Line, HIGH);
		SET_BIT(EXTI -> FTSR, Copy_u8Line);
		break;
		
		case CHANGE:
		GPIO_voidPinDirection(Copyu8Port, Copy_u8Line, INPUT_FLOATING);
		SET_BIT(EXTI -> RTSR, Copy_u8Line);
		SET_BIT(EXTI -> FTSR, Copy_u8Line);
		break;
	}
	/*	chooses port for line-x interrupt	*/
	AFIO_voidEnableEXTI(Copy_u8Line, Copyu8Port);
	/*	sets mask bit to enable interrupt for line-x	*/
	SET_BIT(EXTI -> IMR, Copy_u8Line);
}

void EXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	/*	sets mask bit to enable interrupt for line-x	*/
	SET_BIT(EXTI -> IMR, Copy_u8Line);
}

void EXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	/*	resets mask bit to disable interrupt for line-x	*/
	CLR_BIT(EXTI -> IMR, Copy_u8Line);
}


void EXTI_voidSwInterrupt(u8 Copy_u8Line)
{
	/*	sets mask bit to enable interrupt	*/
	SET_BIT(EXTI -> IMR, Copy_u8Line);
	/*	performs a software interrupt for line-x	*/
	SET_BIT(EXTI -> SWIER, Copy_u8Line);
}


void EXTI0_voidSetCallBack(void (*Copy_FuncPtr) (void))
{
	EXTI0_CallBack = Copy_FuncPtr;
}

void EXTI1_voidSetCallBack(void (*Copy_FuncPtr) (void))
{
	EXTI1_CallBack = Copy_FuncPtr;
}

void EXTI2_voidSetCallBack(void (*Copy_FuncPtr) (void))
{
	EXTI2_CallBack = Copy_FuncPtr;
}

void EXTI3_voidSetCallBack(void (*Copy_FuncPtr) (void))
{
	EXTI3_CallBack = Copy_FuncPtr;
}

void EXTI4_voidSetCallBack(void (*Copy_FuncPtr) (void))
{
	EXTI4_CallBack = Copy_FuncPtr;
}

void EXTI9_5_voidSetCallBack(void (*Copy_FuncPtr) (void))
{
	EXTI9_5_CallBack = Copy_FuncPtr;
}

void EXTI15_10_voidSetCallBack(void (*Copy_FuncPtr) (void))
{
	EXTI15_10_CallBack = Copy_FuncPtr;
}




void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/* clears pending bit */
	SET_BIT(EXTI -> PR, 0); 
}

void EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();
	/* clears pending bit */
	SET_BIT(EXTI -> PR, 1); 
}

void EXTI2_IRQHandler(void)
{
	EXTI2_CallBack();
	/* clears pending bit */
	SET_BIT(EXTI -> PR, 2); 
}

void EXTI3_IRQHandler(void)
{
	EXTI3_CallBack();
	/* clears pending bit */
	SET_BIT(EXTI -> PR, 3); 
}

void EXTI4_IRQHandler(void)
{
	EXTI4_CallBack();
	/* clears pending bit */
	SET_BIT(EXTI -> PR, 4); 
}

void EXTI9_5_IRQHandler(void)
{
	EXTI9_5_CallBack();
	/* clears pending bit */
	(EXTI -> PR) |= 0x000003E0;
}

void EXTI15_10_IRQHandler(void)
{
	EXTI15_10_CallBack();
	/* clears pending bit */
	(EXTI -> PR) |= 0x0000FC00;
}
