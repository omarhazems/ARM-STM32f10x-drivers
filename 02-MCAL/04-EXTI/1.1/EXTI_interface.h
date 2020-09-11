/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.1                                                              */
/* Date      : 10 september 2020                                                 */
/*********************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define		EXTI_LINE_0		0
#define		EXTI_LINE_1		1
#define		EXTI_LINE_2		2
#define		EXTI_LINE_3		3
#define		EXTI_LINE_4		4
#define		EXTI_LINE_5		5
#define		EXTI_LINE_6		6
#define		EXTI_LINE_7		7
#define		EXTI_LINE_8		8
#define		EXTI_LINE_9		9
#define		EXTI_LINE_10	10
#define		EXTI_LINE_11	11
#define		EXTI_LINE_12	12
#define		EXTI_LINE_13	13
#define		EXTI_LINE_14	14
#define		EXTI_LINE_15	15

#define	RISING	 0
#define	FALLING	 1
#define	CHANGE	 2

void EXTI_voidSetEXTI(u8 Copy_u8Line, u8 Copyu8Port, u8 Copy_u8Mode);
void EXTI_voidEnableEXTI(u8 Copy_u8Line);
void EXTI_voidDisableEXTI(u8 Copy_u8Line);
void EXTI_voidSwInterrupt(u8 Copy_u8Line);
void EXTI0_voidSetCallBack(void (*Copy_FuncPtr) (void));
void EXTI1_voidSetCallBack(void (*Copy_FuncPtr) (void));
void EXTI2_voidSetCallBack(void (*Copy_FuncPtr) (void));
void EXTI3_voidSetCallBack(void (*Copy_FuncPtr) (void));
void EXTI4_voidSetCallBack(void (*Copy_FuncPtr) (void));
void EXTI9_5_voidSetCallBack(void (*Copy_FuncPtr) (void));
void EXTI15_10_voidSetCallBack(void (*Copy_FuncPtr) (void));

#endif
