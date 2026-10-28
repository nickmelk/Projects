#ifndef SIGPROC_H
#define SIGPROC_H

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <optional>
#include <numeric>

namespace sigproc
{
    template <typename T>
    bool in_range(T value, T min, T max)
    {
        return value >= min && value <= max;
    }

    template <typename T>
    T clamp(T value, T min, T max)
    {
        if (value < min)
            return min;
        if (value > max)
            return max;
        return value;
    }

    template <typename Iterator>
    Iterator min(Iterator first, Iterator last)
    {
        return std::min_element(first, last);
    }

    template <typename Iterator>
    Iterator max(Iterator first, Iterator last)
    {
        return std::max_element(first, last);
    }

    template <typename Iterator>
    std::optional<double> avg(Iterator first, Iterator last)
    {
        auto count {last - first};
        if (!count)
            return std::nullopt;
        return std::accumulate(first, last, 0.0) / static_cast<double>(count);
    }

    template <typename Iterator, typename Callable>
    std::size_t count_matching(Iterator first, Iterator last, Callable func)
    {
        std::size_t count {};
        for (; first != last; ++first)
            if (func(*first))
                ++count;
        return count;
    }
}

#endif
