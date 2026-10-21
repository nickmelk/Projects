#include "speed_data.h"

#include <algorithm>
#include <numeric>
#include <optional>

void SpeedData::add_measurement(int speed)
{
    if (speed < constants::speed_min || speed > constants::speed_max)
        return;
    if (speed > constants::speed_warning)
        m_overspeed_measurements.push_back(speed);
    m_measurements.push_back(speed);
}

std::optional<int> SpeedData::min() const
{
    if (m_measurements.empty())
        return {};
    return *std::min_element(m_measurements.begin(), m_measurements.end());
}

std::optional<int> SpeedData::max() const
{
    if (m_measurements.empty())
        return {};
    return *std::max_element(m_measurements.begin(), m_measurements.end());
}

std::optional<double> SpeedData::avg() const
{
    if (m_measurements.empty())
        return {};
    return std::accumulate(m_measurements.begin(), m_measurements.end(), 0.0)
        / static_cast<double>(m_measurements.size());
}

std::optional<double> SpeedData::avg_overspeed() const
{
    if (m_overspeed_measurements.empty())
        return {};
    return std::accumulate(m_overspeed_measurements.begin(),
        m_overspeed_measurements.end(), 0.0)
        / static_cast<double>(m_overspeed_measurements.size());
}
