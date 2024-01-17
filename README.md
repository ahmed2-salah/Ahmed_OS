# Simple Operating system based on atmega32 mcu
An operating system (OS) is a software program that acts as an intermediary between  hardware and the user. It manages various hardware and software resources, enabling the execution of applications and the overall functionality of a computer system.

## RTOS Stack
The Real Time operating system stack consists of two Layers:
1. RTOS services.
2. Low level timer.
   That stack is accessing APP layer and Hardware layer directly.
   To provide the RTOS services to application and can access hardware layer to use a low level timer and hardware register.

## OS provided services
1. Create Task
2. Delete Task
3. Start_OS
4. Suspend_Task
5. Resume_Task
6. Scheduler

## Task parameters
1. Pointer to function to point to the task code
2. Task name.
3. Task State    ->(Ready/suspended).
4. Task priority ->(0 is higher priority).
5. Task periodicity.
6. Task First delay.

All of the task parameter are defined as a new type (Task_t) as a structure.
   
