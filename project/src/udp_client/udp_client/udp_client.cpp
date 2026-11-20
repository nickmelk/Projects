#include "udp_client.h"

#include "../constants.h"
#include "../message_data/message_data.h"
#include "../message_queue/message_queue.h"

#include <sys/socket.h>

#include <iostream>

const MessageQueue& UDPClient::queue() const
{
    return m_queue;
}

void UDPClient::bind(const SocketAddress& address)
{
    int error {::bind(m_handler.socket(), (struct sockaddr*)&address,
        sizeof(address))};
    if (error)
    {
        std::cerr << "Failed to bind to an address\n";
        m_ok = false;
    }
}

void UDPClient::receive()
{
    MessageData data {};
    data.bytes = recv(m_handler.socket(), data.buffer.data(),
        constants::buffer_size, 0);
    if (data.bytes < 0)
    {
        std::cerr << "Failed to receive a packet\n";
        m_ok = false;
    }
    else
        m_queue.push(data);
}

UDPClient::operator bool() const
{
    return m_ok;
}
