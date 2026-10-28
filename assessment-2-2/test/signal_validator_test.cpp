#include "../signal_validator/signal_validator.h"

#include <gtest/gtest.h>

using VehicleSpeed = unsigned int;
using EngineRPM = unsigned long;
using CoolantTemperature = int;

template <typename T>
class SignalValidatorTest : public testing::Test
{
protected:
    T m_value {};
    SignalValidator<T, 5L, 95L> m_validator {};
};

using SignalTypes = testing::Types<VehicleSpeed, EngineRPM,
    CoolantTemperature>;

TYPED_TEST_SUITE(SignalValidatorTest, SignalTypes);

TYPED_TEST(SignalValidatorTest, TestValidate)
{
    this->m_value = 100;
    EXPECT_FALSE(this->m_validator.validate(this->m_value));

    this->m_value = 50;
    EXPECT_TRUE(this->m_validator.validate(this->m_value));
}
