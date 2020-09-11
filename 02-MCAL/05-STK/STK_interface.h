/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 1 September 2020                                                  */
/*********************************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


void STK_voidInit(void); 
void STK_voidDelay(u32 Copy_u32Ticks);
void STK_voidOnDelay(u32 Copy_u32Ticks, void (*Copy_FuncPtr)(void));
void STK_voidPeriodicOnDelay(u32 Copy_u32Ticks, void (*Copy_FuncPtr)(void));
void STK_voidStopDelay(void);
u32	 STK_u32GetElapsed(void);
u32	 STK_u32GetRemaining(void);

#endif