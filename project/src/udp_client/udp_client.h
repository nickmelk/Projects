#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include "packet_data.h"
#include "socket_address.h"
#include "socket_handler.h"

class UDPClient
{
public:
    const PacketData& data() const;
    void bind(const SocketAddress& address);
    void receive();
    operator bool() const;

private:
    SocketHandler m_handler {};
    PacketData m_data {};
    bool m_ok {true};
};

#endif
