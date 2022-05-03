/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include "protocol/data_types.h"

#include <array>

static constexpr std::array<int, 2> getOffsets()
{
    std::array<int, 2> offsets = {};

    offsets[static_cast<int>(DataType::UINT8)] = sizeof(uint8_t);
    offsets[static_cast<int>(DataType::UINT16)] = sizeof(uint16_t);

    return offsets;
}

int calculateDataTypeOffset(DataType type)
{
    static constexpr const auto offsets = getOffsets();
    return offsets[static_cast<int>(type)];
}