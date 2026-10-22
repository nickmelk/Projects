#include "vehicle_data.h"

#include <iostream>

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

std::optional<VehicleData> get_vehicle_data()
{
    std::cout << "Enter vehicle speed in km/h: ";
    int speed {};
    std::cin >> speed;

    if (!std::cin || speed < constants::speed_min
        || speed > constants::speed_max)
    {
        std::cout << "Invalid speed\n";
        return std::nullopt;
    }

    std::cout << "Enter engine temperature in degrees C: ";
    int temperature {};
    std::cin >> temperature;

    if (!std::cin || temperature < constants::temp_min
        || temperature > constants::temp_max)
    {
        std::cout << "Invalid temperature\n";
        return std::nullopt;
    }

    return VehicleData{speed, temperature};
}
