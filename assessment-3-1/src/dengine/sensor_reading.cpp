#include "sensor_reading.h"

CoolantTemperatureReading::CoolantTemperatureReading(int value)
    : m_value {value}
{
    
}

int CoolantTemperatureReading::value() const
{
    return m_value;
}
