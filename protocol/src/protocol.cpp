/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include "protocol/protocol.h"

void Protocol::addDataType(DataType type) {
    m_dataTypes.emplace_back(type);
}

std::vector<DataEntry> Protocol::convertToDataEntries(uint8_t *buffer, uint8_t size) {
    const auto requiredSize = getTotalRequiredSize();

    std::vector<DataEntry> data;
    auto offset = 0;

    if(requiredSize != size)
        return {};

    for(const auto & type : m_dataTypes)
    {
        data.emplace_back(type, buffer + offset);
        offset += calculateDataTypeOffset(type);
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
