#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include "../message_processor/message_processor.hpp"
#include "../message_queue/message_queue.hpp"
#include "../socket_address/socket_address.hpp"
#include "../socket_handler/socket_handler.hpp"

class UDPClient
{
public:
    void bind(const SocketAddress& address);
    void receive();
    operator bool() const;

private:
    SocketHandler m_handler {};
    MessageQueue m_queue {};
    bool m_is_valid {true};
    MessageProcessor m_processor {m_queue, m_is_valid};
};

#endif
