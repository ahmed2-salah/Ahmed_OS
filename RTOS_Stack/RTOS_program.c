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
    arrTasks[Copy_u8Priority].Priodicity=Copy_u16Priodicity;
    arrTasks[Copy_u8Priority].TaskFunc=Copy_pvTaskFunc;

}
/***********************************************************************/

static void voidScheduler(void)
{
   static u16 Copy_tickCounter=0;
   u8 TaskCounter=0;

   Copy_tickCounter++;

   /*Looping over all tasks to check periodicity*/

   for(TaskCounter=0;TaskCounter<TaskNum;TaskCounter++)
   {
	   if((Copy_tickCounter%arrTasks[TaskCounter].Priodicity)==0)
	   {
           if(arrTasks[TaskCounter].TaskFunc !=NULL)
           {
        	   arrTasks[TaskCounter].TaskFunc();
           }
           else
           {
        	   /*do nothing*/
           }
	   }
   }

}
