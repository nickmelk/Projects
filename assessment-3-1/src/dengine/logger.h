#ifndef LOGGER_H
#define LOGGER_H

#include "diagnostic_event.h"

class ConsoleLogger
{
    virtual void log(const DiagnosticEvent& event) const = 0;
};

class FileLogger
{
    virtual void flog(const DiagnosticEvent& event, const char* file) const = 0;
};

class EventLogger : public ConsoleLogger, public FileLogger
{
public:
    void log(const DiagnosticEvent& event) const override;
    void flog(const DiagnosticEvent& event, const char* file) const override;
};

#endif
