/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 12 September 2020                                                 */
/*********************************************************************************/

#ifndef _OS_PRIVATE_H
#define _OS_PRIVATE_H


typedef struct
{
	u16 Priodicity;
	void (*Funcptr) (void);
	u16 FirstDelay;
	u8 State;
	
}Task;



#endif
