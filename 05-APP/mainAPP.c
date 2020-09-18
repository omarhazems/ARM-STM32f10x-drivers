#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "OS_interface.h"

void Func0(void);
void Func1(void);
void Func2(void);


void main(void)
{
	/*	 INIT RCC  	*/
	RCC_voidInitSysClock();

	/*    ENABLE RCC FOR GPIOA	 */
	RCC_voidEnableClock(RCC_APB2, 2);

	/*	 GPIO INIT (DIRECTION)	*/
	GPIO_voidPinDirection(GPIOA, PIN0, OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(GPIOA, PIN1, OUTPUT_2MHZ_PP);
	GPIO_voidPinDirection(GPIOA, PIN2, OUTPUT_2MHZ_PP);

	/*	 CREATE TASKS	*/
	OS_voidCreateTask(0, 1000, Func0, 0);
	OS_voidCreateTask(1, 2000, Func1, 1000);
	OS_voidCreateTask(2, 3000, Func2, 2000);

	/*	 START OS	*/
	OS_voidStart();

	while(1)
	{

	}
}


void Func0(void)
{
	GPIO_voidTogglePin(GPIOA, PIN0);
}

void Func1(void)
{
	GPIO_voidTogglePin(GPIOA, PIN1);
}

void Func2(void)
{
	GPIO_voidTogglePin(GPIOA, PIN2);
}
