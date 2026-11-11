#ifndef SOCKET_HANDLER_H
#define SOCKET_HANDLER_H

class SocketHandler
{
public:
    SocketHandler();
    SocketHandler(const SocketHandler& other) = delete;
    SocketHandler& operator=(const SocketHandler& other) = delete;
    SocketHandler(SocketHandler&& other) noexcept;
    SocketHandler& operator=(SocketHandler&& other) noexcept;
    ~SocketHandler();

    int socket() const;

private:
    int m_socket {};
};

#endif
