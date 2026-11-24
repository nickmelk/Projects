#include "udp_client.hpp"

#include "../message/message.hpp"
#include "../socket_address/socket_address.hpp"

#include <sys/socket.h>

#include <iostream>

void UDPClient::bind(const SocketAddress& address)
{
    int error {::bind(m_handler.socket(), (struct sockaddr*)&address.address(),
        sizeof(address.address()))};
    if (error)
    {
        std::cerr << "Failed to bind to an address\n";
        m_is_valid = false;
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
        m_is_valid = false;
    }
    else
        m_queue.push(message);
}

UDPClient::operator bool() const
{
    return m_is_valid;
}
