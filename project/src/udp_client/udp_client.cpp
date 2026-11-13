#include "constants.h"
#include "packet_data.h"
#include "udp_client.h"

#include <sys/socket.h>

#include <iostream>

const PacketData& UDPClient::data() const
{
    return m_data;
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
    m_data.bytes = recv(m_handler.socket(), m_data.buffer.data(),
        constants::buffer_size, 0);
    if (m_data.bytes < 0)
    {
        std::cerr << "Failed to receive a packet\n";
        m_ok = false;
    }
}

UDPClient::operator bool() const
{
    return m_ok;
}
