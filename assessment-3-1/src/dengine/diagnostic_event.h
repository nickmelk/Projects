#ifndef DIAGNOSTIC_EVENT_H
#define DIAGNOSTIC_EVENT_H

#include <string>
#include <string_view>

class DiagnosticEvent
{
public:
    DiagnosticEvent();
    DiagnosticEvent(std::string_view message);
    std::string_view message() const;
    void set_message(std::string_view message);
private:
    std::string m_message {};
};

#endif
