#ifndef SPEED_DATA_H
#define SPEED_DATA_H

#include "constants.h"

#include <optional>
#include <vector>

class SpeedData
{
public:
    const std::vector<int>& overspeed_data() const
    {
        return m_overspeed_measurements;
    }

    int num_overspeed() const
    {
        return m_overspeed_measurements.size();
    }

    void add_measurement(int speed);
    std::optional<int> min() const;
    std::optional<int> max() const;
    std::optional<double> avg() const;
    std::optional<double> avg_overspeed() const;

private:
    std::vector<int> m_measurements {};
    std::vector<int> m_overspeed_measurements {};
};

#endif
