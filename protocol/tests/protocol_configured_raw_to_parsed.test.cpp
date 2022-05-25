/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include "protocol.test.datastruct.h"

#include "protocol/protocol.h"

#include <gtest/gtest.h>

class ConfiguredProtocolTest_RawDataToParsedData : public ::testing::Test
{
protected:
    void SetUp() override
    {
        data.dataUint8 = 10;
        data.dataUint16 = 4592;
        data.dataUint32 = 1029421521;
    }

    Data data;
    Protocol protocol;
};

TEST_F(ConfiguredProtocolTest_RawDataToParsedData, DataConversionWithincorrectSizeReturnNoData)
{
    protocol.addDataType(DataType::UINT8);

    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 0).size(), 0);
}

TEST_F(ConfiguredProtocolTest_RawDataToParsedData, DataConversionWithSingleInputAsInputReturnsData)
{
    protocol.addDataType(DataType::UINT8);

    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 1).size(), 1);
}

TEST_F(ConfiguredProtocolTest_RawDataToParsedData, DataConversionWithSingleInputAsInputReturnsCorrectDataType)
{
    protocol.addDataType(DataType::UINT8);

    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 1)[0].type(), DataType::UINT8);
}

TEST_F(ConfiguredProtocolTest_RawDataToParsedData, DataConversionWithSingleInputAsInputReturnsCorrectData)
{
    protocol.addDataType(DataType::UINT8);

    auto dataEntries = protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 1);
    ASSERT_EQ(dataEntries[0].as<uint8_t>(), data.dataUint8);
}

TEST_F(ConfiguredProtocolTest_RawDataToParsedData, DataConversionWithTwoDifferentInputAsInputReturnsData)
{
    protocol.addDataType(DataType::UINT8);
    protocol.addDataType(DataType::UINT16);

    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 3).size(), 2);
}

TEST_F(ConfiguredProtocolTest_RawDataToParsedData, DataConversionWithTwoDifferentAsInputReturnsCorrectDataType)
{
    protocol.addDataType(DataType::UINT8);
    protocol.addDataType(DataType::UINT16);

    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 3)[1].type(), DataType::UINT16);
}

TEST_F(ConfiguredProtocolTest_RawDataToParsedData, DataConversionWithTwoDifferentAsInputReturnsCorrectData)
{
    protocol.addDataType(DataType::UINT8);
    protocol.addDataType(DataType::UINT16);

    auto dataEntries = protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), 3);
    ASSERT_EQ(dataEntries[1].as<uint16_t>(), data.dataUint16);
}

TEST_F(ConfiguredProtocolTest_RawDataToParsedData, DataConversionWithThreeDifferentInputAsInputReturnsData)
{
    protocol.addDataType(DataType::UINT8);
    protocol.addDataType(DataType::UINT16);
    protocol.addDataType(DataType::UINT32);

    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), sizeof(data)).size(), 3);
}

TEST_F(ConfiguredProtocolTest_RawDataToParsedData, DataConversionWithThreeDifferentAsInputReturnsCorrectDataType)
{
    protocol.addDataType(DataType::UINT8);
    protocol.addDataType(DataType::UINT16);
    protocol.addDataType(DataType::UINT32);

    ASSERT_EQ(protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), sizeof(data))[2].type(), DataType::UINT32);
}

TEST_F(ConfiguredProtocolTest_RawDataToParsedData, DataConversionWithThreeDifferentAsInputReturnsCorrectData)
{
    protocol.addDataType(DataType::UINT8);
    protocol.addDataType(DataType::UINT16);
    protocol.addDataType(DataType::UINT32);

    auto dataEntries = protocol.convertToDataEntries(reinterpret_cast<uint8_t *>(&data), sizeof(data));
    ASSERT_EQ(dataEntries[2].as<uint32_t>(), data.dataUint32);
}