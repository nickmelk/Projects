#ifndef LOGGER_H
#define LOGGER_H

#include "constants.h"

#include <fstream>
#include <string_view>

class ConsoleLogger
{
    virtual void log(std::string_view msg) const = 0;
};

class FileLogger
{
    virtual void flog(std::string_view msg) = 0;
};

class EventLogger : public ConsoleLogger, public FileLogger
{
public:
    EventLogger(const char* log_file = constants::log_file);
    EventLogger(const EventLogger& other) = delete;
    EventLogger& operator=(const EventLogger& other) = delete;
    EventLogger(EventLogger&&) noexcept;
    EventLogger& operator=(EventLogger&&) noexcept;
    ~EventLogger();

    void log(std::string_view msg) const override;
    void flog(std::string_view msg) override;
private:
    std::ofstream m_log_file {};
};

#endif
