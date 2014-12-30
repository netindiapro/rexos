/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2014, Alexey Kramarenko
    All rights reserved.
*/

#ifndef LPC_TIMER_H
#define LPC_TIMER_H

#include "lpc_core.h"

typedef struct {
    unsigned int hpet_start;

} TIMER_DRV;

void lpc_timer_init(CORE* core);
bool lpc_timer_request(CORE* core, IPC* ipc);


#endif // LPC_TIMER_H