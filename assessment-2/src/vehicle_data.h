#ifndef VEHICLE_DATA_H
#define VEHICLE_DATA_H

#include "constants.h"

#include <cstdint>
#include <optional>

class VehicleData
{
public:
    static std::optional<VehicleData> get_vehicle_data(int speed,
        int temperature);
    int speed() const;
    int temperature() const;
    bool has_overspeed() const;
    bool has_overheating() const;

private:
    VehicleData(int speed, int temperature)
        : m_speed {speed}, m_temperature {temperature}
    {
        
    }
    
    int m_speed {};
    int m_temperature {};
};

#endif
