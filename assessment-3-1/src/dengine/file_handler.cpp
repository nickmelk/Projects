#include "file_handler.h"

#include <stdexcept>

FileHandler::FileHandler(const char* log_file)
{
    if (!log_file)
        throw std::invalid_argument("Empty path");
    m_log_file.open(log_file, std::ios::out);
    if (!m_log_file)
        throw std::runtime_error("Failed to open file");
}

FileHandler::FileHandler(FileHandler&& other) noexcept
    : m_log_file {std::move(other.m_log_file)}
{

}

FileHandler& FileHandler::operator=(FileHandler&& other) noexcept
{
    if (this != &other)
        m_log_file = std::move(other.m_log_file);
    return *this;
}

std::ofstream& FileHandler::log_file()
{
    return m_log_file;
}
