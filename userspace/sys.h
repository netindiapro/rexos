/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2019, RExOS team
    All rights reserved.

    author: Alexey E. Kramarenko (alexeyk13@yandex.ru)
*/

#ifndef SYS_H
#define SYS_H

#include "stream.h"
#include "object.h"
#include "types.h"
#include "sys_config.h"

/** \addtogroup sys sys
    \{
 */

__STATIC_INLINE bool open_stdout()
{
    HANDLE stream = object_get(SYS_OBJ_STDOUT);
    if (stream != INVALID_HANDLE)
        __PROCESS->stdout = stream_open(stream);
    return __PROCESS->stdout != INVALID_HANDLE;
}

/**
    \brief open stdid
    \retval true on success
*/

__STATIC_INLINE bool open_stdin()
{
    HANDLE stream = object_get(SYS_OBJ_STDIN);
    if (stream != INVALID_HANDLE)
        __PROCESS->stdin = stream_open(stream);
    return __PROCESS->stdin != INVALID_HANDLE;
}

/**
    \brief close stdout
    \retval none
*/

__STATIC_INLINE void close_stdout()
{
    if (__PROCESS->stdout != INVALID_HANDLE)
        stream_close(__PROCESS->stdout);
}

/**
    \brief close stdin
    \retval none
*/

__STATIC_INLINE void close_stdin()
{
    if (__PROCESS->stdin != INVALID_HANDLE)
        stream_close(__PROCESS->stdin);
}

/** \} */ // end of sys group

#endif // SYS_H
