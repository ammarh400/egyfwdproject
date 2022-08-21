/*
* File Name: Dio.c
*
* Description: Source file for TM4C123GH6PM Dio Driver
*
* Author: Ammar Hassan
*/


#include "sys_timer.h"

/*
* g_timercounter     (global variable): counts the number of elapses seconds
* g_timerCallBackPtr (global variable): pointer to the call back function
* g_seconds          (global variable): the number of seconds
*/
static uint32 g_timercounter;
static void (*g_timerCallBackPtr)(void);
static uint32 g_seconds;

void SysTick_Handler(void)
{
    g_timercounter++;
    if(g_timercounter == g_seconds)
    {
        g_timercounter = 0;
      (*g_timerCallBackPtr)();
    }
}

/*
* Function Name: sys_timer_init
* Parameters (in): ConfigPtr - Pointer to timer configuration data
* Return value: None
* Description: Function to Initialize the systimer module.
*/
void sys_timer_init(const timerConfig * sysTimerConfig)
{
    SYS_CONTROL_REG = 0;
    SYS_CURRENT_REG = 0;
    SET_BIT(SYS_CONTROL_REG , SYS_TICK_CLK_SRC_BIT); /*use system clock*/
    g_timerCallBackPtr = sysTimerConfig->timerCallBack;
}

/*
* Function Name: sys_timer_start
* Parameters (in): uint32 time in seconds
* Return value: None
* Description: Function to start the systimer module.
*/

void sys_timer_start(uint32 time)
{
    SYS_RELOAD_REG = 15999999;
    g_seconds = time;
    SET_BIT(SYS_CONTROL_REG , SYS_TICK_ENABLE_BIT); /*start counting*/
}

/*
* Function Name: sys_timer_stop
* Parameters (in): None
* Return value: None
* Description: Function to stop the systimer module.
*/

void sys_timer_stop(void)
{
    CLEAR_BIT(SYS_CONTROL_REG , SYS_TICK_ENABLE_BIT);
}