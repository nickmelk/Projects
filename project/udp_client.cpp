#include "src/constants.h"
#include "src/socket_handler.h"
#include "gen/schema.pb.h"

#include <array>
#include <iostream>
#include <iomanip>
#include <string>

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

std::array<char, constants::buffer_size> buffer {};
std::size_t bytes_received {};

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
    std::cout << "Received UDP packet: ";
    std::cout << std::setw(3) << bytes_received << 'B';
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

int main()
{
    SocketHandler handler {};

    sockaddr_in server_address {};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(constants::port);
    server_address.sin_addr.s_addr = htonl(constants::ip_address);

    bind(handler.socket(), (struct sockaddr*)&server_address,
        sizeof(server_address));

    while (true)
    {
        sockaddr_in sender_addr {};
        socklen_t sender_len = sizeof(sender_addr);

        bytes_received = recvfrom(handler.socket(), buffer.data(),
            buffer.size(), 0, (struct sockaddr*)&sender_addr, &sender_len);

        ReadingMessage message {};
        bool success {message.ParseFromArray(buffer.data(),
            static_cast<int>(bytes_received))};

        if (success)
            parse_message(message);
        else
            std::cerr << "Failed to parse the packet\n";
    }

    return 0;
}
