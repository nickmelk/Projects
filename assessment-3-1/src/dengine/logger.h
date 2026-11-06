#ifndef LOGGER_H
#define LOGGER_H

#include "constants.h"

#include <fstream>
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
    ~ConsoleLogger() override = default;
    void log(std::string_view msg) override;
};

class FileLogger : public LoggerInterface
{
public:
    explicit FileLogger(const char* log_file = constants::log_file);
    FileLogger(const FileLogger& other) = delete;
    FileLogger& operator=(const FileLogger& other) = delete;
    FileLogger(FileLogger&&) noexcept;
    FileLogger& operator=(FileLogger&&) noexcept;
    ~FileLogger() override = default;

    void log(std::string_view msg) override;

private:
    std::ofstream m_log_file {};
};

#endif
