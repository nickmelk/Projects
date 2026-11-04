#include "constants.h"
#include "diagnostic_rule.h"

const char* CoolantTemperatureRule::evaluate(const SensorReading& reading)
    const
{
    if (reading.value() > constants::coolant_temperature_limit)
        return "Engine overheat";
    else
        return nullptr;
}
