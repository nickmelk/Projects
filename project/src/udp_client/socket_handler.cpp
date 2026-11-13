#include "socket_handler.h"

#include <unistd.h>
#include <sys/socket.h>

#include <iostream>
#include <utility>

SocketHandler::SocketHandler()
    : m_socket {::socket(AF_INET, SOCK_DGRAM, 0)}
{
    if (m_socket < 0)
        std::cerr << "Failed to create a socket\n";
}

SocketHandler::~SocketHandler()
{
    if (m_socket < 0)
        return;
    close(m_socket);
}

SocketHandler::SocketHandler(SocketHandler&& other) noexcept
    : m_socket {std::exchange(other.m_socket, -1)}
{

}

SocketHandler& SocketHandler::operator=(SocketHandler&& other) noexcept
{
    if (this != &other)
        std::swap(m_socket, other.m_socket);
    return *this;
}

int SocketHandler::socket() const
{
    return m_socket;
}
