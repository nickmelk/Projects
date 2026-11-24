#ifndef DIAGNOSTIC_ENGINE_H
#define DIAGNOSTIC_ENGINE_H

#include "diagnostic_rule.hpp"
#include "sensor_reading.hpp"

class DiagnosticEngine
{
public:
    template <typename T, typename Pred>
    void evaluate(SensorReading<T> reading, DiagnosticRule<Pred> rule);
};

template <typename T, typename Pred>
void DiagnosticEngine::evaluate(SensorReading<T> reading,
    DiagnosticRule<Pred> rule)
{
    if (rule.evaluate(reading.value))
    {
        std::string_view message {rule.message()};
        rule.logger().log(message);
    }
}

#endif
