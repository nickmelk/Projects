#include "vehicle_data.h"

#include <iostream>
#include <optional>

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
    std::optional<VehicleData> data {get_vehicle_data()};

    if (data)
        print_stats(*data);

    return 0;
}
