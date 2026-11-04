#ifndef DIAGNOSTIC_ENGINE_H
#define DIAGNOSTIC_ENGINE_H

#include "diagnostic_rule.h"
#include "logger.h"
#include "sensor_reading.h"

class DiagnosticEngine
{
public:
    template <typename T, typename Pred>
    void evaluate(SensorReading<T> reading, DiagnosticRule<Pred> rule);
private:
    EventLogger m_logger {};
};

template <typename T, typename Pred>
void DiagnosticEngine::evaluate(SensorReading<T> reading,
    DiagnosticRule<Pred> rule)
{
    if (rule.evaluate(reading.value))
    {
        std::string_view message {rule.message()};
        m_logger.log(message);
        m_logger.flog(message);
    }
}

#endif
