#include "constants.hpp"
#include "udp_client/udp_client.hpp"

int main()
{
    UDPClient client {constants::ip_address, constants::port};

    client.start();

    return 0;
}
