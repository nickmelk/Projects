#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include "../message_processor/message_processor.hpp"
#include "../socket_handler/socket_handler.hpp"

#include <netinet/in.h>

#include <atomic>
#include <string_view>

class UDPClient
{
public:
    explicit UDPClient(std::string_view address, int port);
    void start();
    void stop();

private:
    void loop();
    void receive();

    SocketHandler m_handler {};
    sockaddr_in m_address {};
    std::atomic_bool m_is_running {};
    MessageProcessor m_processor {};
};

#endif
