#include "assessment-2/src/constants.h"
#include "assessment-2/src/vehicle_data.h"

#include <gtest/gtest.h>

TEST(VehicleDataTest, TestObjectCreation)
{
    // invalid speed, invalid temperature
    std::optional<VehicleData> data1 {
        VehicleData::get_vehicle_data(constants::speed_max+1, constants::temp_max+1)
    };
    EXPECT_FALSE(data1.has_value());

    // invalid speed, valid temperature
    std::optional<VehicleData> data2 {
        VehicleData::get_vehicle_data(constants::speed_max+1, 100)
    };
    EXPECT_FALSE(data2.has_value());

    // valid speed, invalid temperature
    std::optional<VehicleData> data3 {
        VehicleData::get_vehicle_data(100, constants::temp_max+1)
    };
    EXPECT_FALSE(data3.has_value());

    // valid speed, valid temperature
    std::optional<VehicleData> data4 {
        VehicleData::get_vehicle_data(100, 100)
    };
    EXPECT_TRUE(data4.has_value());
}

TEST(VehicleDataTest, TestSpeedAccessor)
{
    std::optional<VehicleData> data {VehicleData::get_vehicle_data(100, 100)};
    EXPECT_EQ(data->speed(), 100);
}

TEST(VehicleDataTest, TestTemperatureAccessor)
{
    std::optional<VehicleData> data {VehicleData::get_vehicle_data(100, 100)};
    EXPECT_EQ(data->temperature(), 100);
}

TEST(VehicleDataTest, TestOverspeedPresence)
{
    // no overspeed
    std::optional<VehicleData> data1 {VehicleData::get_vehicle_data(100, 100)};
    EXPECT_FALSE(data1->has_overspeed());

    // overspeed
    std::optional<VehicleData> data2 {
        VehicleData::get_vehicle_data(constants::speed_warning+1, 100)
    };
    EXPECT_TRUE(data2->has_overspeed());
}

TEST(VehicleDataTest, TestOverheatingPresence)
{
    // no overheating
    std::optional<VehicleData> data1 {VehicleData::get_vehicle_data(100, 100)};
    EXPECT_FALSE(data1->has_overheating());

    // overheating
    std::optional<VehicleData> data2 {
        VehicleData::get_vehicle_data(100, constants::temp_warning+1)
    };
    EXPECT_TRUE(data2->has_overheating());
}

