#include "constants.h"
#include "message_data/message_data.h"
#include "socket_address/socket_address.h"
#include "udp_client/udp_client.h"
#include "gen/schema.pb.h"

#include <chrono>
#include <iostream>
#include <iomanip>

using namespace std::literals::chrono_literals;

template <typename T>
void log(const T& reading, std::string_view message, std::size_t bytes)
{
    std::cout << "Received a packet: ";
    std::cout << std::setw(3) << bytes << 'B';
    std::cout << std::setw(10) << std::setprecision(3) << reading.value();
    std::cout << std::setw(25) << message << '\n';
}

void parse_message(const ReadingMessage& message)
{
    switch (message.reading_case())
    {
    case ReadingMessage::kTemperatureReading:
        log(message.temperature_reading(), message.message(),
            message.ByteSizeLong());
        break;
    case ReadingMessage::kRpmReading:
        log(message.rpm_reading(), message.message(),
            message.ByteSizeLong());
        break;
    case ReadingMessage::kVoltageReading:
        log(message.voltage_reading(), message.message(),
            message.ByteSizeLong());
        break;
    case ReadingMessage::kSpeedReading:
        log(message.speed_reading(), message.message(),
            message.ByteSizeLong());
        break;
    default:
        log(message.temperature_reading(), constants::unknown_reading,
            message.ByteSizeLong());
        break;
    }
}

void parse_data(const MessageData& data)
{
    ReadingMessage message {};
    if (message.ParseFromArray(data.buffer.data(), data.bytes))
        parse_message(message);
    else
        std::cerr << "Failed to parse data\n";
}

int main()
{
    UDPClient client {};
    SocketAddress address {constants::ip_address, constants::port};

    client.bind(address);

    while (client)
    {
        client.receive();
        // std::cout << "Thread: " << std::this_thread::get_id() << " (receiver)\n";
        std::this_thread::sleep_for(1s);
    }

    return 1;
}
