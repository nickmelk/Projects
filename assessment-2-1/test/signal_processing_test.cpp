#include "../signal_processing/signal_processing.h"

#include <gtest/gtest.h>

#include <vector>

using VehicleSpeed = unsigned int;
using EngineRPM = unsigned long;
using CoolantTemperature = int;
using BatteryVoltage = float;

template <typename T>
class SignalProcessingTest : public testing::Test
{
protected:
    T value {};
    T min {5};
    T max {95};
    std::vector<T> data {};
};

using TestTypes = testing::Types<VehicleSpeed, EngineRPM, CoolantTemperature,
    BatteryVoltage>;

TYPED_TEST_SUITE(SignalProcessingTest, TestTypes);

TYPED_TEST(SignalProcessingTest, TestInRange)
{
    this->value = 100;
    EXPECT_FALSE(
        signal_processing::in_range(this->value, this->min, this->max)
    );

    this->value = 50;
    EXPECT_TRUE(
        signal_processing::in_range(this->value, this->min, this->max)
    );
}

TYPED_TEST(SignalProcessingTest, TestClamp)
{
    this->value = 0;
    EXPECT_EQ(
        signal_processing::clamp(this->value, this->min, this->max), this->min
    );

    this->value = 100;
    EXPECT_EQ(
        signal_processing::clamp(this->value, this->min, this->max), this->max
    );

    this->value = 50;
    EXPECT_EQ(
        signal_processing::clamp(this->value, this->min, this->max), this->value
    );
}

TYPED_TEST(SignalProcessingTest, TestMin)
{
    EXPECT_EQ(
        signal_processing::min(this->data.begin(), this->data.end()), this->data.end()
    );

    this->data = {1, 2, 3, 4, 5};
    EXPECT_EQ(*signal_processing::min(this->data.begin(), this->data.end()), static_cast<TypeParam>(1));
}

TYPED_TEST(SignalProcessingTest, TestMax)
{
    EXPECT_EQ(
        signal_processing::max(this->data.begin(), this->data.end()), this->data.end()
    );

    this->data = {1, 2, 3, 4, 5};
    EXPECT_EQ(*signal_processing::max(this->data.begin(), this->data.end()), static_cast<TypeParam>(5));
}

TYPED_TEST(SignalProcessingTest, TestAvg)
{
    EXPECT_FALSE(
        signal_processing::avg(this->data.begin(), this->data.end())
    );

    this->data = {1, 2, 3, 4, 5};
    EXPECT_EQ(*signal_processing::avg(this->data.begin(), this->data.end()), static_cast<TypeParam>(3));
}

TYPED_TEST(SignalProcessingTest, TestCountMatching)
{
    this->data = {50, 200, 100, 20, 150};
    auto func1 {
        [](TypeParam value){return value > 100;}
    };
    EXPECT_EQ(
        signal_processing::count_matching(this->data.begin(), this->data.end(), func1), 2
    );

    auto func2 {[](TypeParam value){return value < 0;}};
    EXPECT_EQ(
        signal_processing::count_matching(this->data.begin(), this->data.end(), func2), 0
    );

    auto func3 {[](TypeParam value){return value > 0;}};
    EXPECT_EQ(
        signal_processing::count_matching(this->data.begin(), this->data.end(), func3), this->data.size()
    );
}
