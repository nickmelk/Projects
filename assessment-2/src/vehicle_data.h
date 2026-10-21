#ifndef VEHICLE_DATA_H
#define VEHICLE_DATA_H

#include "constants.h"

#include <cstdint>
#include <optional>

class VehicleData
{
public:
    int speed() const
    {
        return m_speed;
    }

    int temperature() const
    {
        return m_temperature;
    }

    bool has_overspeed() const;
    bool has_overheating() const;

    friend std::optional<VehicleData> get_vehicle_data();

private:
    VehicleData(int speed, int temperature)
        : m_speed {speed}, m_temperature {temperature}
    {
        
    }
    
    int m_speed {};
    int m_temperature {};
};

std::optional<VehicleData> get_vehicle_data();

#endif
