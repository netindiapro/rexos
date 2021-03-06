/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2019, RExOS team
    All rights reserved.

    author: Alexey E. Kramarenko (alexeyk13@yandex.ru)
*/

#ifndef TI_CONFIG_H
#define TI_CONFIG_H

//---------------------- fast drivers definitions -----------------------------------
#define TI_UART                                 1

//------------------------------------- timer ---------------------------------------------
//Don't change this if you are not sure. Unused if RTC is configured
#define SECOND_PULSE_TIMER                      TIMER_GPT1
#define HPET_TIMER                              TIMER_GPT0

#endif // TI_CONFIG_H
