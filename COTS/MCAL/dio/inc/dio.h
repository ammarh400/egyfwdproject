
/*
* File Name: Dio.c
*
* Description: header file for TM4C123GH6PM Dio Driver
*
* Author: Ammar Hassan
*/

#ifndef PORT_H
#define PORT_H

#include "std_types.h"
#include "common.h"

#define PORTA_ADD           0x40004000
#define PORTB_ADD           0x40005000
#define PROTC_ADD           0x40006000
#define PORTD_ADD           0x40007000
#define PORTE_ADD           0x40024000
#define PORTF_ADD           0x40025000

#define SYSCTL_REGCGC2_REG        (*((volatile uint32 *)0x400FE608))

#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C


void DIO_Init(const pinConfgs *ConfigPtr);
void DIO_PIN_write(pinConfigID pinID, pinStatus);
pinStatus DIO_PIN_read(pinConfigID pinID);


#endif
