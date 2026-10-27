#include "constants.h"
#include "vehicle_data.h"

#include <iostream>

std::optional<VehicleData> VehicleData::get_vehicle_data(int speed,
    int temperature)
{
    if (speed < constants::speed_min || speed > constants::speed_max)
    {
        std::cout << "Invalid speed\n";
        return std::nullopt;
    }

    if (temperature < constants::temp_min || temperature > constants::temp_max)
    {
        std::cout << "Invalid temperature\n";
        return std::nullopt;
    }

    return VehicleData{speed, temperature};
}


int VehicleData::speed() const
{
    return m_speed;
}

int VehicleData::temperature() const
{
    return m_temperature;
}

bool VehicleData::has_overspeed() const
{
    return m_speed > constants::speed_warning;
}

bool VehicleData::has_overheating() const
{
    return m_temperature > constants::temp_warning;
}
