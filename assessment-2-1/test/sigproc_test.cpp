#include "../sigproc/sigproc.h"

#include <gtest/gtest.h>

#include <vector>

using VehicleSpeed = unsigned int;
using EngineRPM = unsigned long;
using CoolantTemperature = int;
using BatteryVoltage = float;

template <typename T>
class SigProcTest : public testing::Test
{
protected:
    T m_value {};
    T m_min {5};
    T m_max {95};
    std::vector<T> m_data {};
};

using SignalTypes = testing::Types<VehicleSpeed, EngineRPM, CoolantTemperature,
    BatteryVoltage>;

TYPED_TEST_SUITE(SigProcTest, SignalTypes);

TYPED_TEST(SigProcTest, TestInRange)
{
    this->m_value = 100;
    EXPECT_FALSE(sigproc::in_range(this->m_value, this->m_min, this->m_max));

    this->m_value = 50;
    EXPECT_TRUE(sigproc::in_range(this->m_value, this->m_min, this->m_max));
}

TYPED_TEST(SigProcTest, TestClamp)
{
    this->m_value = 0;
    EXPECT_EQ(sigproc::clamp(this->m_value, this->m_min, this->m_max),
        this->m_min);

    this->m_value = 100;
    EXPECT_EQ(sigproc::clamp(this->m_value, this->m_min, this->m_max),
        this->m_max);

    this->m_value = 50;
    EXPECT_EQ(sigproc::clamp(this->m_value, this->m_min, this->m_max),
        this->m_value);
}

TYPED_TEST(SigProcTest, TestMin)
{
    EXPECT_FALSE(sigproc::min(this->m_data.begin(), this->m_data.end()));

    this->m_data = {50, 200, 100, 20, 150};
    EXPECT_TRUE(sigproc::min(this->m_data.begin(), this->m_data.end()));
    EXPECT_EQ(*sigproc::min(this->m_data.begin(), this->m_data.end()),
        static_cast<TypeParam>(20));
}

TYPED_TEST(SigProcTest, TestMax)
{
    EXPECT_FALSE(sigproc::max(this->m_data.begin(), this->m_data.end()));

    this->m_data = {50, 200, 100, 20, 150};
    EXPECT_TRUE(sigproc::max(this->m_data.begin(), this->m_data.end()));
    EXPECT_EQ(*sigproc::max(this->m_data.begin(), this->m_data.end()),
        static_cast<TypeParam>(200));
}

TYPED_TEST(SigProcTest, TestAvg)
{
    EXPECT_FALSE(sigproc::avg(this->m_data.begin(), this->m_data.end()));

    this->m_data = {50, 200, 100, 20, 150};
    EXPECT_TRUE(sigproc::avg(this->m_data.begin(), this->m_data.end()));
    EXPECT_EQ(*sigproc::avg(this->m_data.begin(), this->m_data.end()), 104.0);
}

TYPED_TEST(SigProcTest, TestCountMatching)
{
    this->m_data = {50, 200, 100, 20, 150};
    auto begin {this->m_data.begin()};
    auto end {this->m_data.end()};

    auto func1 {
        [](TypeParam value){return value > static_cast<TypeParam>(100);}
    };
    EXPECT_EQ(sigproc::count_matching(begin, end, func1), 2);

    auto func2 {
        [](TypeParam value){return value < static_cast<TypeParam>(0);}
    };
    EXPECT_EQ(sigproc::count_matching(begin, end, func2), 0);

    auto func3 {
        [](TypeParam value){return value > static_cast<TypeParam>(0);}
    };
    EXPECT_EQ(sigproc::count_matching(begin, end, func3), this->m_data.size());
}
