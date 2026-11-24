#ifndef SIGPROC_H
#define SIGPROC_H

#include <cstddef>
#include <iterator>
#include <optional>
#include <stdexcept>

namespace sigproc
{
    template <typename T>
    bool in_range(T value, T min, T max)
    {
        if (min > max)
            throw std::logic_error("Invalid range");
        return value >= min && value <= max;
    }

    template <typename T>
    T clamp(T value, T min, T max)
    {
        if (min > max)
            throw std::logic_error("Invalid range");
        if (value < min)
            return min;
        if (value > max)
            return max;
        return value;
    }

    template <typename Iterator>
    auto min(Iterator first, Iterator last)
    {
        using ValueType = typename std::iterator_traits<Iterator>::value_type;
        std::optional<ValueType> val {};

        for (; first != last; ++first)
            if (!val.has_value() || *first < val)
                val = *first;

        return val;
    }

    template <typename Iterator>
    auto max(Iterator first, Iterator last)
    {
        using ValueType = typename std::iterator_traits<Iterator>::value_type;
        std::optional<ValueType> val {};
        
        for (; first != last; ++first)
            if (!val.has_value() || *first > val)
                val = *first;

        return val;
    }

    template <typename Iterator>
    std::optional<double> avg(Iterator first, Iterator last)
    {
        std::size_t count {};
        double sum {};

        for (; first != last; ++first, ++count)
            sum += *first;

        if (!count)
            return std::nullopt;
        return sum/count;
    }

    template <typename Iterator, typename Predicate>
    std::size_t count_matching(Iterator first, Iterator last, Predicate pred)
    {
        std::size_t count {};
        for (; first != last; ++first)
            if (pred(*first))
                ++count;
        return count;
    }
}

#endif
