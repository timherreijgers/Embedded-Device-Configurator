/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include "protocol/protocol.h"

void Protocol::addDataType(DataType type) {
    m_dataTypes.emplace_back(type);
}

std::vector<DataEntry> Protocol::convertToDataEntries(uint8_t *buffer, uint8_t size) {
    std::vector<DataEntry> data;
    const auto requiredSize = getTotalRequiredSize();
    auto offset = 0;

    if(requiredSize != size)
        return {};

    for(const auto & type : m_dataTypes)
    {
        data.emplace_back(type, buffer + offset);
        offset += 1;
    }

    return data;
}

int Protocol::getTotalRequiredSize() {
    int totalOffset = 0;

    for(const auto & type : m_dataTypes)
    {
        totalOffset += calculateDataTypeOffset(type);
    }

    return totalOffset;
}
