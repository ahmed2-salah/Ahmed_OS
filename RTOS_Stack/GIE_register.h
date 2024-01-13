/********************************************************/
/********************************************************/
/*************** Author: Ahmed_Salah  *******************/
/*************** Layer: RTOS_Stack	  *******************/
/*************** SWC: EXTI			  *******************/
/*************** Date: 13/1/2024 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/


#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_

/********************************************************************************/
/**************** Private Macros For GIE Registers and Bit **********************/
/********************************************************************************/
#define SREG_REG 		*((volatile u8*)0x5F)

#define SREG_I 			7					/*SREG_I Global interrupt enable bit */

#endif /* GIE_REGISTER_H_ */
