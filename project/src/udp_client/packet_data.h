#ifndef PACKET_DATA_H
#define PACKET_DATA_H

#include "constants.h"

#include <sys/types.h>

#include <array>

struct PacketData
{
    std::array<char, constants::buffer_size> buffer {};
    ssize_t bytes {};
};

#endif
