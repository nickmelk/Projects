#include "constants.h"
#include "logger_interface.h"

#include <iostream>

void ConsoleLogger::log(std::string_view msg)
{
    std::cerr << constants::warning_level << ": " << msg << '\n';
}

void FileLogger::log(std::string_view msg)
{
    m_handler.log_file() << constants::warning_level << ": " << msg << '\n';
}
