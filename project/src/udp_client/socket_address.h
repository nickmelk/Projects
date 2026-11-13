#ifndef SOCKET_ADDRESS
#define SOCKET_ADDRESS

#include <netinet/in.h>

#include <string_view>

class SocketAddress
{
public:
    explicit SocketAddress(std::string_view address, int port);

    const sockaddr_in& address() const;

private:
    sockaddr_in m_address {};
};

#endif
