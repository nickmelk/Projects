#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string_view>

namespace constants
{
    constexpr int coolant_temperature_limit {120};
    constexpr unsigned int engine_rpm_limit {7000};
    constexpr double battery_voltage_limit {10.5};
    constexpr float oil_pressure_limit {1.0};

    constexpr std::string_view msg_engine_overheat {"Engine overheat"};
    constexpr std::string_view msg_engine_overspeed {"Engine overspeed"};
    constexpr std::string_view msg_low_battery_voltage {"Low battery voltage"};
    constexpr std::string_view msg_low_oil_pressure {"Low oil pressure"};

    constexpr const char* log_file {"diagnostic.log"};
    constexpr std::string_view warning_level {"[WARNING]"};
}

#endif
