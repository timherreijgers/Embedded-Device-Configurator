/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#pragma once

#include "data_entry.h"
#include "data_types.h"

#include <vector>
#include <inttypes.h>

class Protocol
{
public:
    void addDataType(DataType type);
    std::vector<DataEntry> convertToDataEntries(uint8_t *buffer, uint8_t size);
private:
    std::vector<DataType> m_dataTypes;

    int getTotalRequiredSize();
};