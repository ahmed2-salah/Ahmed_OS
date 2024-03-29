/********************************************************/
/********************************************************/
/*************** Author: Ahmed_Salah  *******************/
/*************** Layer: RTOS stack	  *******************/
/*************** SWC: RTOS		      *******************/
/*************** Date: 13/1/2024 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_


#define Task_Suspended    1
#define Task_Resumed      0

/*Task structure*/
typedef struct
{
	u16 Priodicity;
	void (*TaskFunc)(void);
	u8 State;
	u16 FirstDelay;
}Task_t;

enum Error_type
{
	OK,NOT_OK
};


static void voidScheduler(void);

#endif /* RTOS_PRIVATE_H_ */
