#include "handler.h"

int main()
{
    FileWriter writer {Handler {"test.txt"}};

    writer.write("test");

    return 0;
}
