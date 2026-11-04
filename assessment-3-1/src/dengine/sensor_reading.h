#ifndef SENSOR_READING_H
#define SENSOR_READING_H

enum class SensorReadingType
{
    unknown,
    coolant_temperature,
    engine_rpm,
    battery_voltage,
    oil_pressure,
};

template<typename T>
struct SensorReading
{
    T value {};
    SensorReadingType type {SensorReadingType::unknown};
};

#endif
