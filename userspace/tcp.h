/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2015, Alexey Kramarenko
    All rights reserved.
*/

#ifndef TCP_H
#define TCP_H

#include "ip.h"
#include "io.h"
#include <stdint.h>

#define TCP_PSH                     (1 << 0)
#define TCP_URG                     (1 << 1)

typedef struct {
    uint16_t flags;
    uint16_t urg_len;
} TCP_STACK;

uint16_t tcp_checksum(void* buf, unsigned int size, const IP* src, const IP* dst);
HANDLE tcp_listen(HANDLE tcpip, unsigned short port);
HANDLE tcp_connect(HANDLE tcpip, unsigned short port, const IP* remote_addr);
#define tcp_read(tcpip, handle, io, size)                           io_read((tcpip), HAL_IO_REQ(HAL_TCP, IPC_READ), (handle), (io), (size))
#define tcp_read_sync(tcpip, handle, io, size)                      io_read_sync((tcpip), HAL_IO_REQ(HAL_TCP, IPC_READ), (handle), (io), (size))

#endif // TCP_H
