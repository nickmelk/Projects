#include "udp_client.hpp"

#include "../message/message.hpp"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <chrono>
#include <iostream>
#include <string_view>
#include <thread>

using namespace std::literals::chrono_literals;

UDPClient::UDPClient(std::string_view address, int port)
{
    m_address.sin_family = AF_INET;
    m_address.sin_port = htons(port);
    inet_pton(AF_INET, address.data(), &m_address.sin_addr);
}

void UDPClient::start()
{
    int error {bind(m_handler.socket(), (struct sockaddr*)&m_address,
        sizeof(m_address))};
    if (error)
    {
        std::cerr << "Failed to bind to an address\n";
        stop();
    }
    else
    {
        m_is_running = true;
        m_processor.start(m_is_running);
        loop();
    }
}

void UDPClient::stop()
{
    m_is_running = false;
    m_processor.stop();
}

void UDPClient::loop()
{
    while (m_is_running)
    {
        receive();
        std::this_thread::sleep_for(1s);
    }
}

void UDPClient::receive()
{
    Message message {};
    message.bytes = recv(m_handler.socket(), message.buffer.data(),
        Message::buffer_size, 0);
    if (message.bytes < 0)
    {
        std::cerr << "Failed to receive a packet\n";
        stop();
    }
    else
        m_processor.enqueue(message);
}
