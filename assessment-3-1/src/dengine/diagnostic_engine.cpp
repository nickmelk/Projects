#include "diagnostic_engine.h"
#include "diagnostic_event.h"

const DiagnosticEvent& DiagnosticEngine::event() const
{
    return m_event;
}

void DiagnosticEngine::evaluate(const SensorReading& reading)
{
    const char* result {m_rule.evaluate(reading)};
    m_event.set_message(result);
}
