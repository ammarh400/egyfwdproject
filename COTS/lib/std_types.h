/*
* File Name: std_types.h
*
* Description: header file for TM4C123GH6PM user defined types
*
* Author: Ammar Hassan
*/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define NULL_PTR          ((void *)0)

#define STD_HIGH        0x01
#define STD_LOW         0x00



#define STD_ON          0x01
#define STD_OFF         0x00


typedef unsigned char         uint8;
typedef signed char           sint8;
typedef unsigned short        uint16;
typedef signed short          sint16;
typedef unsigned long         uint32;
typedef signed long           sint32;
typedef unsigned long long    uint64;
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;


typedef enum {
    lEDID = 0,
    NUM_OF_PINS,
}pinConfigID;

typedef enum {
    HIGH,
    LOW,
}pinStatus;

typedef enum {
    PORTA = 0,
    PORTB = 1,
    PORTC = 2,
    PORTD = 3,
    PORTE = 4,
    PORTF = 5,
}portID;

typedef enum {
    PIN0 = 0,
    PIN1 = 1,
    PIN2 = 2,
    PIN3 = 3,
    PIN4 = 4,
    PIN5 = 5,
    PIN6 = 6,
    PIN7 = 7,
}pinID;

/* Description: Enum to hold p direction */

typedef enum {
    INDIR = 0,
    OUTDIR = 1,
}pinDir;

/* Description: Enum to hold pin resistor */

typedef enum {
    PULLUP = 0,
    PULLDOWN = 1,
    NOA = 2,
}inResType;

/* Description: Structure to configure each individual pin:
 *    portNo the portNo Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *    pinNo the number of the pin in the port.
 *  pinDr the direction of pin
 *  inRe the internal resistor
 *  pinOffset offset address of the pin
 */

typedef struct {
    portID portNo;
    pinID pinNo;
    pinDir pinDr;
    inResType inRes;
    uint32 pinOffset;
}pinConfg;

typedef struct {
    pinConfg pins [NUM_OF_PINS];
}pinConfgs;

typedef struct {
    void (*timerCallBack)(void);
}timerConfig;
#endif
