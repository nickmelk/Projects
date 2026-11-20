#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include "../message_processor/message_processor.h"
#include "../message_queue/message_queue.h"
#include "../socket_address/socket_address.h"
#include "../socket_handler/socket_handler.h"

class UDPClient
{
public:
    const MessageQueue& queue() const;
    void bind(const SocketAddress& address);
    void receive();
    operator bool() const;

private:
    SocketHandler m_handler {};
    MessageQueue m_queue {};
    MessageProcessor m_processor {m_queue};
    bool m_ok {true};
};

#endif
