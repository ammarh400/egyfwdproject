
#include "std_types.h"
#include "common.h"

#define SYS_CONTROL_REG       (*((volatile uint32 *)0xE000E010))
#define SYS_RELOAD_REG        (*((volatile uint32 *)0xE000E014))
#define SYS_CURRENT_REG       (*((volatile uint32 *)0xE000E018))

#define SYS_TICK_CLK_SRC_BIT   2
#define SYS_TICK_ENABLE_BIT    0

void sys_timer_init(const timerConfig * sysTimerConfig);

void sys_timer_start(uint32 time);

void sys_timer_stop(void);