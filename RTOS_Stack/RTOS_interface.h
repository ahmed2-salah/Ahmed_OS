/********************************************************/
/********************************************************/
/*************** Author: Ahmed_Salah  *******************/
/*************** Layer: RTOS stack	  *******************/
/*************** SWC: RTOS		      *******************/
/*************** Date: 13/1/2024 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void RTOS_voidStart(void);


void RTOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_u16Priodicity , void (*Copy_pvTaskFunc) (void));


void RTOS_voidSuspendTask(u8 Copy_u8Priority);


void RTOS_voidResumeTask(u8 Copy_u8Priority);


void RTOS_voidDeleteTask(u8 Copy_u8Priority);

#endif /* RTOS_INTERFACE_H_ */
