#include "constants.h"
#include "udp_client.h"

#include <sys/socket.h>

#include <iostream>

const Packet& UDPClient::packet() const
{
    return m_packet;
}

void UDPClient::bind(unsigned int address, int port)
{
    m_address.sin_family = AF_INET;
    m_address.sin_port = htons(port);
    m_address.sin_addr.s_addr = htonl(address);
    ::bind(m_handler.socket(), (struct sockaddr*)&m_address,
        sizeof(m_address));
}

void UDPClient::receive()
{
    m_packet.bytes = recvfrom(m_handler.socket(), m_packet.data,
        constants::buffer_size, 0, nullptr, nullptr);
    if (m_packet.bytes < 0)
        std::cerr << "Failed to receive a packet\n";
}
