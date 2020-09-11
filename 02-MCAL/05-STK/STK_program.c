/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 1 September 2020                                                  */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

void (*callback) (void);
u8 ODF = 0;
 
void STK_voidInit(void)
{
	#if CLK_SRC == STK_AHB_8
	
		STK_CTRL = 0x00000000;
	
	#elif CLK_SRC == STK_AHB
	
		STK_CTRL = 0x00000004;
		
	#endif
}

void STK_voidDelay(u32 Copy_u32Ticks)
{
	STK_LOAD = Copy_u32Ticks;
	STK_CTRL |= 0x00000001;
	while((GET_BIT(STK_CTRL,16)) == 0);
	STK_CTRL &= ~(0x00000001);
	
}

void STK_voidOnDelay(u32 Copy_u32Ticks, void (*Copy_FuncPtr)(void))
{
	STK_LOAD = Copy_u32Ticks;
	STK_CTRL |= 0x00000003;
	callback = Copy_FuncPtr;
	ODF = 1;
}

void STK_voidPeriodicOnDelay(u32 Copy_u32Ticks, void (*Copy_FuncPtr)(void))
{
	STK_LOAD = (Copy_u32Ticks - 1);
	STK_CTRL |= 0x00000003;
	callback = Copy_FuncPtr;
}

void STK_voidStopDelay(void)
{
	STK_CTRL &= ~(0x00000003);
	STK_LOAD = 0;
	STK_VAL = 0;
}

u32	 STK_u32GetElapsed(void)
{
	u32 Local_u23STKVal = 0;
	Local_u23STKVal = STK_VAL ;
	return Local_u23STKVal;
}

u32	 STK_u32GetRemaining(void)
{
	u32 Local_u23STKVal = 0;
	u8  Local_u8STK_LOAD_val = STK_LOAD;
	u8  Local_u8STK_VAL_val  = STK_VAL;
	Local_u23STKVal = (Local_u8STK_LOAD_val - Local_u8STK_VAL_val);
	return Local_u23STKVal;
}

void SysTick_Handler(void)
{
	u8 Local_u8InterruptFlag = 0;
	if (ODF == 1)
	{
		ODF = 0;
		STK_CTRL &= ~(0x00000003);
		STK_LOAD = 0;
		STK_VAL = 0;
	}
	callback();
	Local_u8InterruptFlag = GET_BIT(STK_CTRL,16);
}