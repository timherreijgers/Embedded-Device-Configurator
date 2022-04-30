/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include "protocol/protocol.h"

void Protocol::addDataType(DataType type) {
    m_entries.emplace_back();
}

std::vector<DataEntry> Protocol::convertToDataEntries(uint8_t *buffer, uint8_t size) {
    return m_entries;
}
