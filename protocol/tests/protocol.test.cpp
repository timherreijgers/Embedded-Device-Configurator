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

TEST(Protocoltest, DataConversionWithincorrectSizeReturnNoData)
{
    Protocol protocol;
    protocol.addDataType(DataType::UINT8);

    Data data;
    data.dataUint8 = 10;
    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 0).size(), 0);
}

TEST(ProtocolTest, DataConversionWithSingleInputAsInputReturnsData)
{
    Protocol protocol;
    protocol.addDataType(DataType::UINT8);

    Data data;
    data.dataUint8 = 10;
    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 1).size(), 1);
}

TEST(ProtocolTest, DataConversionWithSingleInputAsInputReturnsCorrectDataType)
{
    Protocol protocol;
    protocol.addDataType(DataType::UINT8);

    Data data;
    data.dataUint8 = 10;
    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 1)[0].type(), DataType::UINT8);
}

TEST(ProtocolTest, DataConversionWithSingleInputAsInputReturnsCorrectData)
{
    Protocol protocol;
    protocol.addDataType(DataType::UINT8);

    Data data;
    data.dataUint8 = 10;

    auto dataEntries = protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 1);
    ASSERT_EQ(dataEntries[0].as<uint8_t>(), data.dataUint8);
}

TEST(ProtocolTest, DataConversionWithTwoDifferentInputAsInputReturnsData)
{
    Protocol protocol;
    protocol.addDataType(DataType::UINT8);
    protocol.addDataType(DataType::UINT16);

    Data data;
    data.dataUint8 = 10;
    data.dataUint16 = 4592;
    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 3).size(), 2);
}

TEST(ProtocolTest, DataConversionWithTwoDifferentAsInputReturnsCorrectDataType)
{
    Protocol protocol;
    protocol.addDataType(DataType::UINT8);
    protocol.addDataType(DataType::UINT16);

    Data data;
    data.dataUint8 = 10;
    data.dataUint16 = 4592;
    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 3)[1].type(), DataType::UINT16);
}

TEST(ProtocolTest, DataConversionWithTwoDifferentAsInputReturnsCorrectData)
{
    Protocol protocol;
    protocol.addDataType(DataType::UINT8);
    protocol.addDataType(DataType::UINT16);

    Data data = {};
    data.dataUint8 = 10;
    data.dataUint16 = 4592;

    auto dataEntries = protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 3);
    ASSERT_EQ(dataEntries[1].as<uint16_t>(), data.dataUint16);
}