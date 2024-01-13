/********************************************************/
/********************************************************/
/*************** Author: Ahmed_Salah  *******************/
/*************** Layer: RTOS stack	  *******************/
/*************** SWC: RTOS		      *******************/
/*************** Date: 13/1/2024 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/
#include"STD_TYPES.h"

#include"Timer0_interface.h"
#include"GIE_interface.h"

#include"RTOS_private.h"
#include"RTOS_interface.h"
#include"RTOS_config.h"
/***********************************************************************/

/*Creating Array of structs (Tasks)*/
Task_t arrTasks[TaskNum]={{NULL}};

/***********************************************************************/
void RTOS_voidStart(void)
{
	TIMER0_u8SetCallBackCTCMode(&voidScheduler);
	GIE_voidEnable();
	TIMER0_voidInit();
}

/***********************************************************************/
u8 RTOS_u8CreateTask(u8 Copy_u8Priority , u16 Copy_u16Priodicity , void (*Copy_pvTaskFunc) (void),u16 Copy_u16FirstDelay)
{
    u8 Local_errorState = OK;

	if(arrTasks[Copy_u8Priority].TaskFunc==NULL)
	{
		arrTasks[Copy_u8Priority].Priodicity=Copy_u16Priodicity;
		arrTasks[Copy_u8Priority].TaskFunc=Copy_pvTaskFunc;
		arrTasks[Copy_u8Priority].State=Task_Resumed;  /*Initial state for the task*/
		arrTasks[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
	}
	else
	{
		/*Priority is reserved before by another task */
		Local_errorState=NOT_OK;
	}

	return Local_errorState;

}
/***********************************************************************/
void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	arrTasks[Copy_u8Priority].State=Task_Suspended;
}
/***********************************************************************/
void RTOS_voidResumeTask(u8 Copy_u8Priority)
{
	arrTasks[Copy_u8Priority].State=Task_Resumed;
}
/***********************************************************************/
static void voidScheduler(void)
{
   u8 TaskCounter=0;


	/*Looping over all tasks to check periodicity*/
	for(TaskCounter=0;TaskCounter<TaskNum;TaskCounter++)
	{

		if(arrTasks[TaskCounter].State==Task_Resumed)
		{
			if(arrTasks[TaskCounter].FirstDelay==0)
			{
				/*Execute Task*/
				if(arrTasks[TaskCounter].TaskFunc !=NULL)
				{
					arrTasks[TaskCounter].TaskFunc();
					/*assign Priodicity minus one to task first delay*/
					arrTasks[TaskCounter].FirstDelay=arrTasks[TaskCounter].Priodicity-1;
				}
				else
				{
					/*do nothing*/
				}
			}
			else
			{
				arrTasks[TaskCounter].FirstDelay--;
			}
		}
		else
		{
			/*Task is Suspended and Do NO thing */
		}
	}

}
