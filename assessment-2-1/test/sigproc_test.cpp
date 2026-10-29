#include "../sigproc/sigproc.h"

#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

using VehicleSpeed = unsigned int;
using EngineRPM = unsigned long;
using CoolantTemperature = int;
using BatteryVoltage = float;

template <typename T>
class ScalarDataTest : public testing::Test
{
protected:
    T m_min {5};
    T m_max {95};
    T m_in {50};
    T m_out_min {0};
    T m_out_max {100};
};

template <typename T>
class VectorDataTest : public testing::Test
{
protected:
    std::vector<T> m_empty {};
    std::vector<T> m_filled {0, 20, 40, 60, 80, 100};
    T m_min {0};
    T m_max {100};
    T m_avg {50};
};

using SignalTypes = testing::Types<VehicleSpeed, EngineRPM, CoolantTemperature,
    BatteryVoltage>;

TYPED_TEST_SUITE(ScalarDataTest, SignalTypes);
TYPED_TEST_SUITE(VectorDataTest, SignalTypes);

TYPED_TEST(ScalarDataTest, TestInRangeValueOutOfRange)
{
    EXPECT_FALSE(sigproc::in_range(this->m_out_min, this->m_min, this->m_max));
}

TYPED_TEST(ScalarDataTest, TestInRangeValueInRange)
{
    EXPECT_TRUE(sigproc::in_range(this->m_in, this->m_min, this->m_max));
}

TYPED_TEST(ScalarDataTest, TestInRangeMinMaxSwapped)
{
    EXPECT_THROW(sigproc::in_range(this->m_in, this->m_max, this->m_min),
        std::logic_error);
}

TYPED_TEST(ScalarDataTest, TestClampValueLessThanMin)
{
    EXPECT_EQ(sigproc::clamp(this->m_out_min, this->m_min, this->m_max),
        this->m_min);
}

TYPED_TEST(ScalarDataTest, TestClampValueGreaterThanMax)
{
    EXPECT_EQ(sigproc::clamp(this->m_out_max, this->m_min, this->m_max),
        this->m_max);
}

TYPED_TEST(ScalarDataTest, TestClampValueInRange)
{
    EXPECT_EQ(sigproc::clamp(this->m_in, this->m_min, this->m_max),
        this->m_in);
}

TYPED_TEST(ScalarDataTest, TestClampMinMaxSwapped)
{
    EXPECT_THROW(sigproc::clamp(this->m_in, this->m_max, this->m_min),
        std::logic_error);
}

TYPED_TEST(VectorDataTest, TestMinEmptySequence)
{
    EXPECT_FALSE(sigproc::min(this->m_empty.begin(), this->m_empty.end()));
}

TYPED_TEST(VectorDataTest, TestMinFilledSequence)
{
    auto result {sigproc::min(this->m_filled.begin(), this->m_filled.end())};
    EXPECT_TRUE(result);
    EXPECT_EQ(*result, this->m_min);
}

TYPED_TEST(VectorDataTest, TestMaxEmptySequence)
{
    EXPECT_FALSE(sigproc::max(this->m_empty.begin(), this->m_empty.end()));
}

TYPED_TEST(VectorDataTest, TestMaxFilledSequence)
{
    auto result {sigproc::max(this->m_filled.begin(), this->m_filled.end())};
    EXPECT_TRUE(result);
    EXPECT_EQ(*result, this->m_max);
}

TYPED_TEST(VectorDataTest, TestAvgEmptySequence)
{
    EXPECT_FALSE(sigproc::avg(this->m_empty.begin(), this->m_empty.end()));
}

TYPED_TEST(VectorDataTest, TestAvgFilledSequence)
{
    auto result {sigproc::avg(this->m_filled.begin(), this->m_filled.end())};
    EXPECT_TRUE(result);
    EXPECT_EQ(*result, this->m_avg);
}

TYPED_TEST(VectorDataTest, TestCountMatchingSomethingMatched)
{
    auto pred {
        [](TypeParam value){return value > static_cast<TypeParam>(50);}
    };
    auto result {
        sigproc::count_matching(
            this->m_filled.begin(), this->m_filled.end(), pred
        )
    };
    EXPECT_EQ(result, 3);
}

TYPED_TEST(VectorDataTest, TestCountMatchingNothingMatched)
{
    auto pred {
        [](TypeParam value){return value < static_cast<TypeParam>(0);}
    };
    auto result {
        sigproc::count_matching(
            this->m_filled.begin(), this->m_filled.end(), pred
        )
    };
    EXPECT_EQ(result, 0);
}

TYPED_TEST(VectorDataTest, TestCountMatchingEverythingMatched)
{
    auto pred {
        [](TypeParam value){return value >= static_cast<TypeParam>(0);}
    };
    auto result {
        sigproc::count_matching(
            this->m_filled.begin(), this->m_filled.end(), pred
        )
    };
    EXPECT_EQ(result, this->m_filled.size());
}
