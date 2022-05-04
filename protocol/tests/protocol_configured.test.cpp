/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include "protocol.test.datastruct.h"

#include "protocol/protocol.h"

#include <gtest/gtest.h>

class ConfiguredProtocolTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        data.dataUint8 = 10;
        data.dataUint16 = 4592;
    }

    Data data;
    Protocol protocol;
};

TEST_F(ConfiguredProtocolTest, DataConversionWithincorrectSizeReturnNoData)
{
    protocol.addDataType(DataType::UINT8);

    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 0).size(), 0);
}

TEST_F(ConfiguredProtocolTest, DataConversionWithSingleInputAsInputReturnsData)
{
    protocol.addDataType(DataType::UINT8);

    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 1).size(), 1);
}

TEST_F(ConfiguredProtocolTest, DataConversionWithSingleInputAsInputReturnsCorrectDataType)
{
    protocol.addDataType(DataType::UINT8);

    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 1)[0].type(), DataType::UINT8);
}

TEST_F(ConfiguredProtocolTest, DataConversionWithSingleInputAsInputReturnsCorrectData)
{
    protocol.addDataType(DataType::UINT8);

    auto dataEntries = protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 1);
    ASSERT_EQ(dataEntries[0].as<uint8_t>(), data.dataUint8);
}

TEST_F(ConfiguredProtocolTest, DataConversionWithTwoDifferentInputAsInputReturnsData)
{
    protocol.addDataType(DataType::UINT8);
    protocol.addDataType(DataType::UINT16);

    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 3).size(), 2);
}

TEST_F(ConfiguredProtocolTest, DataConversionWithTwoDifferentAsInputReturnsCorrectDataType)
{
    protocol.addDataType(DataType::UINT8);
    protocol.addDataType(DataType::UINT16);

    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 3)[1].type(), DataType::UINT16);
}

TEST_F(ConfiguredProtocolTest, DataConversionWithTwoDifferentAsInputReturnsCorrectData)
{
    protocol.addDataType(DataType::UINT8);
    protocol.addDataType(DataType::UINT16);

    auto dataEntries = protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 3);
    ASSERT_EQ(dataEntries[1].as<uint16_t>(), data.dataUint16);
}