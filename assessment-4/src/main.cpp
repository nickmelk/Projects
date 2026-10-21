#include <array>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <optional>

template <typename T, std::size_t N>
std::optional<T> calculate_average(const std::array<T, N>& values)
{
    if (values.empty())
        return {};
    return std::accumulate(values.begin(), values.end(), 0)
        / values.size();
}

int main()
{
    std::array<int, 5> speeds {60, 80, 100, 90, 70};
    auto average {calculate_average(speeds)};

    if (average)
        std::cout << *average << '\n';
    else
        std::cout << "No data\n";

    return 0;
}
