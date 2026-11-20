#ifndef MESSAGE_DATA_H
#define MESSAGE_DATA_H

#include "../constants.h"

#include <sys/types.h>

#include <array>

struct MessageData
{
    std::array<char, constants::buffer_size> buffer {};
    ssize_t bytes {};
};

#endif
