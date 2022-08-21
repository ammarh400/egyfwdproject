/*
* File Name: led_blink.c
*
* Description: Source file for TM4C123GH6PM led blinking
*
* Author: Ammar Hassan
*/

#include "led_blink.h"

extern const pinConfgs pinConfigurations;
void SYSTimerCallBack(void);

static timerConfig g_sysTimerConfiguration = {.timerCallBack = SYSTimerCallBack};

/*
* onTime     (global variable) : indicates how much seconds the led will be on
* offtime    (global variable) : indicates how much seconds the led will be off
* ledStatus  (global variable) : status of the led
* timerfired (global variable) : flag will be set in the call back function
*/
static uint32 onTime = 4;
static uint32 offTime = 2;
static uint8 ledStatus = LOW;
static uint8 timerFired = 1;

void SYSTimerCallBack(void)
{
    timerFired = 1;
}

void run()
{
    DIO_Init(&pinConfigurations);
    sys_timer_init(&g_sysTimerConfiguration);
    enableSysTickInt();

    for(;;)
    {
        if (timerFired)
        {
            timerFired = 0;
            if (ledStatus == LOW)
            {
                LED_ON();
                ledStatus = HIGH;
                sys_timer_start(onTime);
            }
            else
            {
                LED_OFF();
                ledStatus = LOW;
                sys_timer_start(offTime);
            }
        }
    }

}