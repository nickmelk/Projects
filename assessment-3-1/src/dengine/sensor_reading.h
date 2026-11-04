#ifndef SENSOR_READING_H
#define SENSOR_READING_H

class SensorReading
{
public:
    virtual ~SensorReading() = default;
    virtual int value() const = 0;
};

class CoolantTemperatureReading : public SensorReading
{
public:
    CoolantTemperatureReading(int value);
    int value() const override;
private:
    int m_value {};
};

// class EngineRPMValidator : public SensorReading
// {
// public:
//     unsigned int value {};
//     bool validate() const override;
// };

// class BatteryVoltageValidator : public SensorReading
// {
// public:
//     double value {};
//     bool validate() const override;
// };

// class OilPressureValidator : public SensorReading
// {
// public:
//     float value {};
//     bool validate() const override;
// };

#endif
