#include "socket_address.hpp"

#include <arpa/inet.h>
#include <netinet/in.h>

#include <string_view>

SocketAddress::SocketAddress(std::string_view address, int port)
{
    m_address.sin_family = AF_INET;
    m_address.sin_port = htons(port);
    inet_pton(AF_INET, address.data(), &m_address.sin_addr);
}

const sockaddr_in& SocketAddress::address() const
{
    return m_address;
}
