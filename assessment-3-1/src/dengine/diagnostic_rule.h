#ifndef DiAGNOSTIC_RULE_H
#define DIAGNOSTIC_RULE_H

#include "sensor_reading.h"

class DiagnosticRule
{
public:
    virtual ~DiagnosticRule() = default;
    virtual const char* evaluate(const SensorReading& reading) const = 0;
};

class CoolantTemperatureRule : public DiagnosticRule
{
public:
    const char* evaluate(const SensorReading& reading) const override;
};

#endif
