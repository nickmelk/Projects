#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#define SPEED_MIN 0
#define SPEED_MAX 200
#define SPEED_WARN 130

class SpeedData
{
public:
    std::vector<int> overspeed_data() const
    {
        return m_overspeed_measurements;
    }

    void add_measurement(int speed)
    {
        if (speed < SPEED_MIN || speed >= SPEED_MAX)
            return;
        if (speed > SPEED_WARN)
            m_overspeed_measurements.push_back(speed);

        m_measurements.push_back(speed);
    }

    int min() const
    {
        return *std::min_element(m_measurements.begin(), m_measurements.end());
    }

    int max() const
    {
        return *std::max_element(m_measurements.begin(), m_measurements.end());
    }

    double avg() const
    {
        return std::accumulate(m_measurements.begin(), m_measurements.end(), 0)
               / static_cast<double>(m_measurements.size());
    }

    int num_overspeed() const
    {
        return m_overspeed_measurements.size();
    }

    double avg_overspeed() const
    {
        return std::accumulate(m_overspeed_measurements.begin(), m_overspeed_measurements.end(), 0)
               / static_cast<double>(m_overspeed_measurements.size());
    }

private:
    std::vector<int> m_measurements {};
    std::vector<int> m_overspeed_measurements {};
};

void get_speed_data(SpeedData& data)
{
    while (true)
    {
        std::cout << "Enter vehicle speed (-1 to exit): ";
        int input {};
        std::cin >> input;
        
        if (input == -1)
            break;
        
        data.add_measurement(input);
    }
}

std::ostream& operator<<(std::ostream& out, std::vector<int> vect)
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
    std::cout << "\nMinimum speed: " << data.min() << " km/h\n";
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
