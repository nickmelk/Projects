#include <array>
#include <iostream>
#include <numeric>

double calculate_average(const std::array<int, 5> values)
{
    return std::accumulate(values.begin(), values.end(), 0.0)
           / values.size();
}

int main()
{
    std::array<int, 5> speeds {60, 80, 100, 90, 70};
    double average {calculate_average(speeds)};

    std::cout << average << '\n';

    return 0;
}
