#include "assessment-1-2/lib/vehicle_data.h"

#include <iostream>
#include <optional>

int get_speed()
{
    std::cout << "Enter vehicle speed in km/h: ";
    int speed {};
    std::cin >> speed;
    return speed;
}

int get_temperature()
{
    std::cout << "Enter engine temperature in degrees C: ";
    int temperature {};
    std::cin >> temperature;
    return temperature;
}

void print_warning_summary(VehicleData data)
{
    bool has_warnings {false};

    if (data.has_overspeed())
    {
        std::cout << "WARNING: Speed is too high\n";
        has_warnings = true;
    }
    if (data.has_overheating())
    {
        std::cout << "WARNING: Engine temparature is too high\n";
        has_warnings = true;
    }
    if (!has_warnings)
    {
        std::cout << "No warnings. All good\n";
    }
}

void print_stats(VehicleData data)
{
    std::cout << "Vehicle speed: " << data.speed() << " km/h\n";
    std::cout << "Engine temperature: " << data.temperature() << " C\n";
    print_warning_summary(data);
}

int main()
{
    int speed {get_speed()};
    int temperature {get_temperature()};

    std::optional<VehicleData> data {
        VehicleData::get_vehicle_data(speed, temperature)
    };

    if (data)
        print_stats(*data);

    return 0;
}
