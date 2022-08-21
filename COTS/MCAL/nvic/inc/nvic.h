#include "std_types.h"
#include "common.h"

#define NVIC_BASE_ADD                   0xE000E000
#define SYSTICK_CTRL_OFFSET             0x010
#define SYSTICK_PRIO_OFFSET             0xD20
#define EN0_OFFSET                      0x100
#define EN1_OFFSET                      0x104
#define EN2_OFFSET                      0x108
#define EN3_OFFSET                      0x10c
#define EN4_OFFSET                      0x110

#define DIS0_OFFSET                     0x180
#define DIS1_OFFSET                     0x184
#define DIS2_OFFSET                     0x188
#define DIS3_OFFSET                     0x18c
#define DIS4_OFFSET                     0x190

#define SYSTICK_PRIO_MASK               0x1FFFFFFF
#define SYSTICK_PRIO_POS                29

#define GET_REG(REG_BASE, OFFSET) (*((volatile uint32 *)(REG_BASE + OFFSET)))

void enableInt(uint32 intNum);
void disableInt(uint32 intNum);
void enableSysTickInt();
void disableSysTickInt();
void setSysTickPriority(uint8 priority);

