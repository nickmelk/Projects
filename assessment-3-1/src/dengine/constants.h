#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string_view>

namespace constants
{
    constexpr int coolant_temperature_limit {120};
    constexpr unsigned int engine_rpm_limit {7000};
    constexpr double battery_voltage_limit {10.5};
    constexpr float oil_pressure_limit {1.0};

    constexpr std::string_view info_msg {"[INFO]"};
    constexpr std::string_view warning_msg {"[WARNING]"};
    constexpr std::string_view error_msg {"[ERROR]"};
    // constexpr int events_max {50};
}

#endif
