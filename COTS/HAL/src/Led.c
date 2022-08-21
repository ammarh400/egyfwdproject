/*
* File Name: Led.c
*
* Description: Source file for TM4C123GH6PM led
*
* Author: Ammar Hassan
*/

#include "Led.h"

/*
* Function Name: LED_ON
* Parameters (in): None
* Return value: None
* Description: Function to turn on the led.
*/

void LED_ON()
{
    DIO_PIN_write(lEDID, HIGH);
}

/*
* Function Name: LED_OFF
* Parameters (in): None
* Return value: None
* Description: Function to turn off the led.
*/

void LED_OFF()
{
    DIO_PIN_write(lEDID, LOW);
}