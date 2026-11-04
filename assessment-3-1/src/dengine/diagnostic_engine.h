#ifndef DIAGNOSTIC_ENGINE_H
#define DIAGNOSTIC_ENGINE_H

#include "diagnostic_event.h"
#include "diagnostic_rule.h"
#include "sensor_reading.h"

class DiagnosticEngine
{
public:
    const DiagnosticEvent& event() const;
    void evaluate(const SensorReading& reading);
private:
    CoolantTemperatureRule m_rule {};
    DiagnosticEvent m_event {};
    // std::array<DiagnosticEvent, constants::events_max> m_events {};
};

#endif
