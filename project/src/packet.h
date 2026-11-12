#ifndef PACKET_H
#define PACKET_H

#include "constants.h"

#include <netinet/in.h>

// #include <array>

struct Packet
{
    // std::array<char, constants::buffer_size> data {};
    char data[constants::buffer_size] {};
    ssize_t bytes {};
};

#endif
