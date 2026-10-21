#include "speed_data.h"

#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>

void get_speed_data(SpeedData& data)
{
    std::cout << "Enter speed data (space separated): ";
    std::string input {};
    std::getline(std::cin, input);

    std::istringstream stream {input};
    int value {};
    while (stream >> value)
        data.add_measurement(value);
}

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vect)
{
    out << '[';
    for (std::size_t i {}; i < vect.size(); ++i)
    {
        out << vect[i];
        if (i < vect.size()-1)
            out << ", ";
    }
    out << ']';

    return out;
}

void print_speed_data(const SpeedData& data)
{
    if (data.empty())
    {
        std::cout << "No data\n";
        return;
    }

    std::cout << "Minimum speed: " << *data.min() << " km/h\n";
    std::cout << "Maximum speed: " << *data.max() << " km/h\n";
    std::cout << "Average speed: " << *data.avg() << " km/h\n";
    std::cout << "Overspeed measurements: "
              << data.overspeed_measurements() << '\n';
    std::cout << "Number of overspeed occurrences: "
              << data.overspeed_occurences() << '\n';
    std::cout << "Average speed: " << *data.avg_overspeed() << " km/h\n";
}

int main()
{
    SpeedData data {};
    get_speed_data(data);

    print_speed_data(data);

    return 0;
}
