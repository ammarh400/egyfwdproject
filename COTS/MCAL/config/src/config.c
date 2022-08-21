/*
* File Name: config.c
*
* Description: Source file for TM4C123GH6PM Dio Driver configurations
*
* Author: Ammar Hassan
*/

#include "std_types.h"

const pinConfgs pinConfigurations= {
    .pins = {{PORTF, PIN1, OUTDIR, NOA, 0x3fc}}
};
