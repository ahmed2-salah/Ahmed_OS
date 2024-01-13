/*
 * main.c
 *
 *  Created on: Jan 13, 2024
 *      Author: Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_Math.h"

#include"PORT_interface.h"
#include"DIO_interface.h"
#include"CLCD_interface.h"
#include"RTOS_interface.h"


void Task_1(void);
void Task_2(void);
void Task_3(void);


void main(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	/*Create Task 1*/
	RTOS_voidCreateTask(0, 1000, &Task_1);
	/*Create Task 2*/
	RTOS_voidCreateTask(1, 2000, &Task_2);
	/*Create Task 3*/
	RTOS_voidCreateTask(2, 3000, &Task_3);

	/*Start OS*/
	RTOS_voidStart();

	while(1)
	{

	}

}

void Task_1(void)
{
	static u8 local_LED_state=0;
	TOGGLE_BIT(local_LED_state,0);
	DIO_enumSetPinValue(DIO_PORTA, DIO_PIN0, local_LED_state);
	CLCD_voidClearLCD();
	CLCD_voidSendString("Hello I am Task1");

}
void Task_2(void)
{
	static u8 local_LED_state=0;
	TOGGLE_BIT(local_LED_state,0);
	DIO_enumSetPinValue(DIO_PORTA, DIO_PIN1, local_LED_state);
	CLCD_voidClearLCD();
	CLCD_voidSendString("Hello I am Task2");
}
void Task_3(void)
{
	static u8 local_LED_state=0;
	TOGGLE_BIT(local_LED_state,0);
	DIO_enumSetPinValue(DIO_PORTA, DIO_PIN2, local_LED_state);
	CLCD_voidClearLCD();
	CLCD_voidSendString("Hello I am Task3");
}
