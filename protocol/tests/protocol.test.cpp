/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include "protocol/protocol.h"
#include "protocol.test.datastruct.h"

#include <gtest/gtest.h>

TEST(ProtocolTest, DataConversionNoInputReturnsNoData)
{
    Protocol protocol;
    ASSERT_EQ(protocol.convertToDataEntries(nullptr, 0).size(), 0);
}

TEST(ProtocolTest, DataConversionWithInputReturnsNoData)
{
    Protocol protocol;

    uint8_t buffer = 10;
    ASSERT_EQ(protocol.convertToDataEntries(&buffer, 1).size(), 0);
}
