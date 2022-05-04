/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#pragma once

enum class DataType
{
    UINT8,
    UINT16,
    UINT32
};

int calculateDataTypeOffset(DataType type);
