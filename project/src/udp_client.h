#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include "packet.h"

#include "socket_handler.h"

#include <netinet/in.h>

class UDPClient
{
public:
    const Packet& packet() const;
    void bind(unsigned int address, int port);
    void receive();

private:
    SocketHandler m_handler {};
    sockaddr_in m_address {};
    Packet m_packet {};
};

#endif
