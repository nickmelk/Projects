#include "constants.hpp"
#include "socket_address/socket_address.hpp"
#include "udp_client/udp_client.hpp"

#include <chrono>

using namespace std::literals::chrono_literals;

int main()
{
    UDPClient client {};
    SocketAddress address {constants::ip_address, constants::port};

    client.bind(address);

    while (client)
    {
        client.receive();
        std::this_thread::sleep_for(1s);
    }

    return 1;
}
