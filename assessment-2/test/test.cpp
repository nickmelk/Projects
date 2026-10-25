#include "assessment-2/src/vehicle_data.h"

#include <gtest/gtest.h>

TEST(VehicleDataTest, TestObjectCreation)
{
    std::optional<VehicleData> data {VehicleData::get_vehicle_data(100, 70)};
    EXPECT_TRUE(data.has_value());
}

TEST(VehicleDataSpeedTest, TestOverspeed)
{
    std::optional<VehicleData> data {VehicleData::get_vehicle_data(160, 70)};
    EXPECT_FALSE(data->has_overspeed());
}

