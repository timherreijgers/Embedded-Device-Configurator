/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include "protocol/data_types.h"

#include <array>
#include <cinttypes>

static constexpr std::array<int, 3> getOffsets()
{
    std::array<int, 3> offsets = {};

    offsets[static_cast<int>(DataType::UINT8)] = sizeof(uint8_t);
    offsets[static_cast<int>(DataType::UINT16)] = sizeof(uint16_t);
    offsets[static_cast<int>(DataType::UINT32)] = sizeof(uint32_t);

    return offsets;
}

int calculateDataTypeOffset(DataType type)
{
    static constexpr const auto offsets = getOffsets();
    return offsets[static_cast<int>(type)];
}