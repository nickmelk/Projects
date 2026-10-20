#include <cstdint>
#include <iostream>

#define SPEED_MIN 0
#define SPEED_MAX 200
#define SPEED_WARN 130
#define TEMP_MIN -40
#define TEMP_MAX 150
#define TEMP_WARN 105

class VehicleData
{
public:
    int speed() const
    {
        return m_speed;
    }

    void set_speed(int speed)
    {
        if (speed < SPEED_MIN || speed >= SPEED_MAX)
            return;
        if (speed > SPEED_WARN)
            m_warning_flags |= overspeed;
        m_speed = speed;
    }

    int temperature() const
    {
        return m_temperature;
    }

    void set_temperature(int temperature)
    {
        if (temperature < TEMP_MIN || temperature >= TEMP_MAX)
            return;
        if (temperature > TEMP_WARN)
            m_warning_flags |= overheating;
        m_temperature = temperature;
    }

    std::uint8_t warnings() const
    {
        return m_warning_flags;
    }

    const static std::uint8_t overspeed {0x01};
    const static std::uint8_t overheating {0x02};

private:
    int m_speed {};
    int m_temperature {};
    std::uint8_t m_warning_flags {};
};

void print_stats(VehicleData data)
{
    std::cout << "\nVehicle speed: " << data.speed() << " km/h\n";
    std::cout << "Engine temperature: " << data.temperature() << " C\n";
    if (data.warnings() & VehicleData::overspeed)
        std::cout << "WARNING: Speed is too high\n";
    if (data.warnings() & VehicleData::overheating)
        std::cout << "WARNING: Engine temparature is too high\n";
    if (!data.warnings())
        std::cout << "No warnings. All good\n";
}

int main()
{
    VehicleData data {};

    std::cout << "Enter vehicle speed in km/h: ";
    int speed {};
    std::cin >> speed;
    data.set_speed(speed);

    std::cout << "Enter engine temperature in degrees C: ";
    int temperature {};
    std::cin >> temperature;
    data.set_temperature(temperature);

    print_stats(data);

    return 0;
}
