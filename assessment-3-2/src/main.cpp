#include "handler.h"

#include <memory>

int main()
{
    auto file_handler = std::make_shared<Handler>("test.txt");

    file_handler->write("test");

    return 0;
}
