#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string_view>

namespace constants
{
    constexpr std::string_view ip_address {"127.0.0.1"};
    constexpr int port {5005};
    constexpr int buffer_size {1024};

    constexpr std::string_view unknown_reading {"Unknown reading"};
}

#endif
