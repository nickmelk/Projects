#include "speed_data.h"

#include <algorithm>
#include <iostream>

void get_speed_data(SpeedData& data)
{
    std::cout << "Enter speed data (space separated): ";
    int input {};
    std::cin >> input;
    data.add_measurement(input);
}

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vect)
{
    out << '[';
    for (int i {}; i < vect.size(); ++i)
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
    std::cout << "Minimum speed: " << data.min() << " km/h\n";
    std::cout << "Maximum speed: " << data.max() << " km/h\n";
    std::cout << "Average speed: " << data.avg() << " km/h\n";
    std::cout << "Overspeed measurements: " << data.overspeed_data() << '\n';
    std::cout << "Number of overspeed occurrences: " << data.num_overspeed() << '\n';
    std::cout << "Average speed: " << data.avg_overspeed() << " km/h\n";
}

int main()
{
    SpeedData data {};
    get_speed_data(data);

    print_speed_data(data);

    return 0;
}
