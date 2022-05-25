/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include "protocol/protocol.h"
#include "protocol.test.datastruct.h"

#include <gtest/gtest.h>

class ProtocolTest : public ::testing::Test
{
protected:
    Protocol _protocol;
    uint8_t _buffer = 10;
};

TEST_F(ProtocolTest, DataConversionNoInputReturnsNoData)
{
    ASSERT_EQ(_protocol.convertToDataEntries(nullptr, 0).size(), 0);
}

TEST_F(ProtocolTest, DataConversionWithInputReturnsNoData)
{

    ASSERT_EQ(_protocol.convertToDataEntries(&_buffer, 1).size(), 0);
}
