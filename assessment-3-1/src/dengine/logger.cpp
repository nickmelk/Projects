#include "constants.h"
#include "logger.h"

#include <iostream>
#include <stdexcept>

void ConsoleLogger::log(std::string_view msg)
{
    std::cerr << constants::warning_level << ": " << msg << '\n';
}

FileLogger::FileLogger(const char* log_file)
{
    if (!log_file)
        throw std::invalid_argument("Empty path");
    m_log_file.open(log_file, std::ios::out);
    if (!m_log_file)
        throw std::runtime_error("Failed to open file");
}

FileLogger::FileLogger(FileLogger&& other) noexcept
    : m_log_file {std::move(other.m_log_file)}
{

}

FileLogger& FileLogger::operator=(FileLogger&& other) noexcept
{
    if (this != &other)
        m_log_file = std::move(other.m_log_file);
    return *this;
}

void FileLogger::log(std::string_view msg)
{
    m_log_file << constants::warning_level << ": " << msg << '\n';
}
