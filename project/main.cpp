#include "src/constants.h"
#include "src/packet.h"
#include "src/udp_client.h"
#include "gen/schema.pb.h"

#include <iostream>
#include <iomanip>
#include <string>

enum class ReadingType
{
    unknown_reading = 0,
    temperature_reading = 1,
    rpm_reading = 2,
    voltage_reading = 3,
    speed_reading = 4,
};

template <typename T>
void log(const T& reading, std::string_view message)
{
    std::cout << std::setw(10) << std::setprecision(3) << reading.value();
    std::cout << std::setw(25) << message << '\n';
}

void parse_message(const ReadingMessage& message)
{
    ReadingType type {static_cast<ReadingType>(message.reading_case()-1)};
    switch (type)
    {
    case ReadingType::temperature_reading:
        log(message.temperature_reading(), message.message());
        break;
    case ReadingType::rpm_reading:
        log(message.rpm_reading(), message.message());
        break;
    case ReadingType::voltage_reading:
        log(message.voltage_reading(), message.message());
        break;
    case ReadingType::speed_reading:
        log(message.speed_reading(), message.message());
        break;
    default:
        log(message.temperature_reading(), constants::unknown_reading);
        break;
    }
}

void parse_packet(const Packet& packet)
{
    ReadingMessage message {};
    bool success {message.ParseFromArray(packet.data, static_cast<int>(packet.bytes))};
    if (success)
    {
        std::cout << "Received UDP packet: ";
        std::cout << std::setw(3) << packet.bytes << 'B';
        parse_message(message);
    }
    else
        std::cerr << "Failed to parse the packet\n";
}

int main()
{
    UDPClient client {};
    client.bind(constants::ip_address, constants::port);

    while (true)
    {
        client.receive();
        parse_packet(client.packet());
    }

    return 0;
}
