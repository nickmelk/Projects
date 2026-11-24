#ifndef MESSAGE_H
#define MESSAGE_H

#include <sys/types.h>

#include <array>

struct Message
{
    static constexpr int buffer_size {1024};

    std::array<char, buffer_size> buffer {};
    ssize_t bytes {};
};

#endif
