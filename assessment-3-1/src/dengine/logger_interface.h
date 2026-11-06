#ifndef LOGGER_INTERFACE_H
#define LOGGER_INTERFACE_H

#include "constants.h"
#include "file_handler.h"

#include <string_view>

class LoggerInterface
{
public:
    virtual ~LoggerInterface() = default;
    virtual void log(std::string_view msg) = 0;
};

class ConsoleLogger : public LoggerInterface
{
public:
    void log(std::string_view msg) override;
};

class FileLogger : public LoggerInterface
{
public:
    void log(std::string_view msg) override;

private:
    FileHandler m_handler {constants::log_file};
};

namespace logging
{
    inline ConsoleLogger c_logger {};
    inline FileLogger f_logger {};
}

#endif
