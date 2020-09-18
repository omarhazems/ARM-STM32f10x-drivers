/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 12 September 2020                                                 */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define	NULL	(int)(void *)0

/*	ARRAY OF STRUCTURE(TASKS)*/
static Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};
static void Scheduler (void);


void OS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Priodicity, void (*Copy_Funcptr) (void), u16 Copy_u16FirstDelay )
{
	OS_Tasks[Copy_u8Priority].Priodicity = Copy_u16Priodicity;
	OS_Tasks[Copy_u8Priority].Funcptr = Copy_Funcptr;
	OS_Tasks[Copy_u8Priority].FirstDelay = Copy_u16FirstDelay;
}

void OS_voidStart(void)
{
	/*	INITIALIZATION	*/
	STK_voidInit();
	/*	Tick = 1msec [periodic]*/
	STK_voidPeriodicOnDelay(1000, Scheduler);

}

void Scheduler (void)
{
	for (u8 i=0 ; i < NUMBER_OF_TASKS ; i++)
	{
		if ( OS_Tasks[i].FirstDelay == 0 )
		{
			OS_Tasks[i].FirstDelay  = (OS_Tasks[i].Priodicity) - 1;
			OS_Tasks[i].Funcptr();
		}
		else 
		{
			OS_Tasks[i].FirstDelay --;
		}
	}
}
