#include "assessment-1-2/lib/constants.hpp"
#include "assessment-1-2/lib/vehicle_data.hpp"

#include <gtest/gtest.h>

TEST(VehicleDataTest, TestObjectCreation)
{
    std::optional<VehicleData> data1 {
        VehicleData::get_vehicle_data(constants::speed_max+1, constants::temp_max+1)
    };
    EXPECT_FALSE(data1.has_value());

    std::optional<VehicleData> data2 {
        VehicleData::get_vehicle_data(constants::speed_max+1, 100)
    };
    EXPECT_FALSE(data2.has_value());

    std::optional<VehicleData> data3 {
        VehicleData::get_vehicle_data(100, constants::temp_max+1)
    };
    EXPECT_FALSE(data3.has_value());

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
    std::optional<VehicleData> data1 {VehicleData::get_vehicle_data(100, 100)};
    EXPECT_FALSE(data1->has_overspeed());

    std::optional<VehicleData> data2 {
        VehicleData::get_vehicle_data(constants::speed_warning+1, 100)
    };
    EXPECT_TRUE(data2->has_overspeed());
}

TEST(VehicleDataTest, TestOverheatingPresence)
{
    std::optional<VehicleData> data1 {VehicleData::get_vehicle_data(100, 100)};
    EXPECT_FALSE(data1->has_overheating());

    std::optional<VehicleData> data2 {
        VehicleData::get_vehicle_data(100, constants::temp_warning+1)
    };
    EXPECT_TRUE(data2->has_overheating());
}

