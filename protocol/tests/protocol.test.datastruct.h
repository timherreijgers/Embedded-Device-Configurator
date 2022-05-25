/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#pragma once

#include <cinttypes>

#ifdef __GNUC__
#define PACK( __Declaration__ ) __Declaration__ __attribute__((__packed__))
#endif

#ifdef _MSC_VER
#define PACK( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop))
#endif

PACK(struct Data
{
    uint8_t dataUint8;
    uint16_t dataUint16;
    uint32_t dataUint32;
});
