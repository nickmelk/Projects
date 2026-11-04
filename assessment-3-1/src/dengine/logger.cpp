#include "constants.h"
#include "logger.h"

#include <iostream>
#include <fstream>

EventLogger::EventLogger(const char* log_file)
    : m_log_file {log_file}
{

}

EventLogger::EventLogger(EventLogger&& other) noexcept
    : m_log_file {std::move(other.m_log_file)}
{

}

EventLogger& EventLogger::operator=(EventLogger&& other) noexcept
{
    if (this != &other)
        m_log_file = std::move(other.m_log_file);
    return *this;
}

EventLogger::~EventLogger()
{
    m_log_file.close();
}

void EventLogger::log(std::string_view msg) const
{
    std::cout << constants::warning_level << ": " << msg << '\n';
}

void EventLogger::flog(std::string_view msg)
{
    m_log_file << constants::warning_level << ": " << msg << '\n';
}
