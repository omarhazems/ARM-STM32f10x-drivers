/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 22 August 2020                                                    */
/*********************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H



void EXTI_voidInit(void);
void EXTI_voidSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);
void EXTI_voidEnableEXTI(u8 Copy_u8Line);
void EXTI_voidDisableEXTI(u8 Copy_u8Line);
void EXTI_voidSwTrigger(u8 Copy_u8Line);
void EXTI_voidSetCallBack(void (*Copy_FuncPtr) (void));


#endif