/*********************************************************************************/
/* Author    : Omar Hazem                                                        */
/* Version   : V1.0                                                              */
/* Date      : 12 September 2020                                                 */
/*********************************************************************************/

#ifndef _OS_INTERFACE_H
#define _OS_INTERFACE_H


void OS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Priodicity, void (*Copy_Funcptr) (void), u16 Copy_u16FirstDelay );
void OS_voidStart(void);



#endif