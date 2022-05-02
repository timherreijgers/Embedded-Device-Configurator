/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#pragma once

#include <inttypes.h>

#pragma pack(1)
struct Data
{
    uint8_t dataUint8;
    uint16_t dataUint16;
    char stringBuffer32[32];
};
#pragma pack(0)