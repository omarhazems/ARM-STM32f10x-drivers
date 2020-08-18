/*****************************************************************************************/
/*Author    : Omar Hazem																 */
/*Version   : V01																		 */
/* Date     : 8 August 2020 															 */
/*****************************************************************************************/

#ifndef _RCC_config_H
#define _RCC_config_H


/* options: RCC_HSE_CRYSTAL 
			RCC_HSE_RC
			RCC_HSI
			RCC_PLL			*/
			
#define	RCC_CLOCK_TYPE	RCC_HSE_CRYSTAL



/* options:	RCC_PLL_IN_HHSI_DIV_2
			RCC_PLL_IN_HSE_DIV_2
			RCC_PLL_IN_HSE	*/

/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL 
#define	RCC_PLL_INPUT
#endif

/* options 2 to 16 */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL 
#define	RCC_PLL_MUL_VAL	
#endif


#endif
