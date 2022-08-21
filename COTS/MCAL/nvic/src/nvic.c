/*
* File Name: nvic.c
*
* Description: Source file for TM4C123GH6PM nivc driver
*
* Author: Ammar Hassan
*/

#include "nvic.h"

static const uint32 g_enableRegsOffsets[] = {EN0_OFFSET, EN1_OFFSET, EN2_OFFSET, EN3_OFFSET, EN4_OFFSET};

/*
* Function Name: enableInt
* Parameters (in): intNum
* Return value: None
* Description: Function to enble the interrupt of the module.
*/

void enableInt(uint32 intNum)
{
    uint32 offset = g_enableRegsOffsets[intNum / 32];
    SET_BIT(GET_REG(NVIC_BASE_ADD, offset), intNum & 31);
}

/*
* Function Name: disableInt
* Parameters (in): intNum
* Return value: None
* Description: Function to disable the interrupt of the module.
*/

void disableInt(uint32 intNum)
{
    uint32 offset = g_enableRegsOffsets[intNum / 32];
    CLEAR_BIT(GET_REG(NVIC_BASE_ADD, offset), intNum & 31);
}

void enableSysTickInt()
{
    SET_BIT(GET_REG(NVIC_BASE_ADD, SYSTICK_CTRL_OFFSET), 1);

}

void disableSysTickInt()
{
    CLEAR_BIT(GET_REG(NVIC_BASE_ADD, SYSTICK_CTRL_OFFSET), 1);
}

/*
* Function Name: setSysTickPriority
* Parameters (in): priority
* Return value: None
* Description: Function to set the priority of  the interrupt
*/
void setSysTickPriority(uint8 priority)
{
    GET_REG(NVIC_BASE_ADD, SYSTICK_PRIO_OFFSET) = (GET_REG(NVIC_BASE_ADD, SYSTICK_PRIO_OFFSET) & SYSTICK_PRIO_MASK) | (priority << SYSTICK_PRIO_POS);
}