/*
* File Name: Dio.c
*
* Description: Source file for TM4C123GH6PM Dio Driver
*
* Author: Ammar Hassan
*/

#include "dio.h"

/*
* pinConfg (global variable) : ptr to pin configuration array
*/
static  const pinConfg * PinConf = NULL_PTR;

/*
* Function Name: Dio_Init
* Parameters (in): ConfigPtr - Pointer to pin configuration data
* Return value: None
* Description: Function to Initialize the Dio module.
*/
void DIO_Init(const pinConfgs * ConfigPtr )
{
    volatile uint32 * PinGpio_Ptr = NULL_PTR;

    PinConf = ConfigPtr->pins;
    uint8 Pin_Index;


    for (Pin_Index = 0; Pin_Index < NUM_OF_PINS ; Pin_Index++)
    {
        switch(PinConf[Pin_Index].portNo)
        {
            case  PORTA:
             PinGpio_Ptr = (volatile uint32 *)PORTA_ADD;
             break;
            case  PORTB:
             PinGpio_Ptr = (volatile uint32 *)PORTB_ADD;
             break;
            case  PORTC:
             PinGpio_Ptr = (volatile uint32 *)PROTC_ADD;
             break;
            case  PORTD:
             PinGpio_Ptr = (volatile uint32 *)PORTD_ADD;
             break;
            case  PORTE:
             PinGpio_Ptr = (volatile uint32 *)PORTE_ADD;
             break;
            case  PORTF:
             PinGpio_Ptr = (volatile uint32 *)PORTF_ADD;
             break;
        }
        int i=0;
        SYSCTL_REGCGC2_REG |= (1<<PinConf[Pin_Index].portNo);
        for(i=0;i<20;i++){}

        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PinGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PinConf[Pin_Index].pinNo);

        if(PinConf[Pin_Index].pinDr == OUTDIR)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PinGpio_Ptr + PORT_DIR_REG_OFFSET) , PinConf[Pin_Index].pinNo);
        }
        else if(PinConf[Pin_Index].pinDr == INDIR)
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PinGpio_Ptr + PORT_DIR_REG_OFFSET) , PinConf[Pin_Index].pinNo);

            if(PinConf[Pin_Index].inRes == PULLUP)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PinGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , PinConf[Pin_Index].pinNo);
            }
            else if(PinConf[Pin_Index].inRes == PULLDOWN)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PinGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , PinConf[Pin_Index].pinNo);
            }
            else
            {
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PinGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , PinConf[Pin_Index].pinNo);
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PinGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , PinConf[Pin_Index].pinNo);
            }
         }
        else
        {
        }

    }
}

/*
* Function Name: DIO_PIN_write
* Parameters (in): pinID enum indicates the index of the pin in PinConf
* Parameters (in): state enum indicates the level of the pin
* Return value: None
* Description: Function to set the level of a pin.
*/

void DIO_PIN_write(pinConfigID pinID, pinStatus state)
{
    volatile uint32 * PinGpio_Ptr = NULL_PTR;
    switch(PinConf[pinID].portNo) // pinNo
    {
        case  PORTA:
         PinGpio_Ptr = (volatile uint32 *)PORTA_ADD + PinConf[pinID].pinOffset;
         break;
        case  PORTB:
         PinGpio_Ptr = (volatile uint32 *)((volatile uint32)PORTB_ADD + PinConf[pinID].pinOffset);
         break;
        case  PORTC:
         PinGpio_Ptr = (volatile uint32 *)((volatile uint32)PROTC_ADD + PinConf[pinID].pinOffset);
         break;
        case  PORTD:
         PinGpio_Ptr = (volatile uint32 *)((volatile uint32)PORTD_ADD + PinConf[pinID].pinOffset);
         break;
        case  PORTE:
         PinGpio_Ptr = (volatile uint32 *)((volatile uint32)PORTE_ADD + PinConf[pinID].pinOffset);
         break;
        case  PORTF:
         PinGpio_Ptr = (volatile uint32 *)((volatile uint32)PORTF_ADD + PinConf[pinID].pinOffset);
         break;
    }
    if(state == HIGH)
    {

        SET_BIT(*PinGpio_Ptr, PinConf[pinID].pinNo);
    }
    else if(state == LOW)
    {

        CLEAR_BIT(*PinGpio_Ptr, PinConf[pinID].pinNo);
    }
}

/*
* Function Name: DIO_PIN_read
* Parameters (in): pinID enum indicates the index of the pin in PinConf
* Return value: pinStatus
* Description: Function to read the level of a pin.
*/
pinStatus DIO_PIN_read(pinConfigID pinID)
{
    volatile uint32 * PinGpio_Ptr = NULL_PTR;
    pinStatus output;
    switch(PinConf[pinID].portNo) //pinNo
    {
        case  PORTA:
         PinGpio_Ptr = (volatile uint32 *)PORTA_ADD + PinConf[pinID].pinOffset;
         break;
        case  PORTB:
         PinGpio_Ptr = (volatile uint32 *)PORTB_ADD + PinConf[pinID].pinOffset;
         break;
        case  PORTC:
         PinGpio_Ptr = (volatile uint32 *)PROTC_ADD + PinConf[pinID].pinOffset;
         break;
        case  PORTD:
         PinGpio_Ptr = (volatile uint32 *)PORTD_ADD + PinConf[pinID].pinOffset;
         break;
        case  PORTE:
         PinGpio_Ptr = (volatile uint32 *)PORTE_ADD + PinConf[pinID].pinOffset;
         break;
        case  PORTF:
         PinGpio_Ptr = (volatile uint32 *)PORTF_ADD + PinConf[pinID].pinOffset;
         break;
    }

    if(BIT_IS_SET(*PinGpio_Ptr, PinConf[pinID].pinNo))
    {
        output = STD_HIGH;
    }
    else
    {
        output = STD_LOW;
    }
    return output;
}


