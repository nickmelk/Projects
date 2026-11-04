#include "constants.h"
#include "logger.h"

#include <iostream>
#include <fstream>

void EventLogger::log(const DiagnosticEvent& event) const
{
    std::cout << constants::warning_msg << ": " << event.message() << '\n';
}

void EventLogger::flog(const DiagnosticEvent& event, const char* file) const
{
    std::ofstream out_file {file};
    out_file << constants::warning_msg << ": " << event.message() << '\n';
    out_file.close();
}
