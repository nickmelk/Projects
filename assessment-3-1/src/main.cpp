#include "dengine/constants.h"
#include "dengine/diagnostic_engine.h"
#include "dengine/diagnostic_rule.h"
#include "dengine/sensor_reading.h"

int main()
{
    DiagnosticEngine engine {};
    RuleGenerator generator {};

    SensorReading<int> coolant_temperature_reading {100};
    SensorReading<unsigned int> engine_rpm_reading {7500U};
    SensorReading<double> battery_voltage_reading {10.5};
    SensorReading<float> oil_pressure_reading {0.5F};

    DiagnosticRule ct_rule {generator.generate(
        [](int value) {return value > constants::coolant_temperature_limit;},
        constants::msg_engine_overheat, logging::f_logger

    )};
    DiagnosticRule erpm_rule {generator.generate(
        [](unsigned int value) {return value > constants::engine_rpm_limit;},
        constants::msg_engine_overspeed, logging::c_logger
    )};
    DiagnosticRule bv_rule {generator.generate(
        [](double value) {return value < constants::battery_voltage_limit;},
        constants::msg_low_battery_voltage, logging::c_logger

    )};
    DiagnosticRule op_rule {generator.generate(
        [](float value) {return value < constants::oil_pressure_limit;},
        constants::msg_low_oil_pressure, logging::f_logger
    )};

    engine.evaluate(coolant_temperature_reading, ct_rule);
    engine.evaluate(engine_rpm_reading, erpm_rule);
    engine.evaluate(battery_voltage_reading, bv_rule);
    engine.evaluate(oil_pressure_reading, op_rule);

    return 0;
}
