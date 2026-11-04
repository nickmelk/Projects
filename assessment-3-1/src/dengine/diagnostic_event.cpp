#include "diagnostic_event.h"

DiagnosticEvent::DiagnosticEvent()
    : m_message {}
{

}

DiagnosticEvent::DiagnosticEvent(std::string_view message)
    : m_message {message}
{

}

std::string_view DiagnosticEvent::message() const
{
    return m_message;
}

void DiagnosticEvent::set_message(std::string_view message)
{
    m_message = message;
}
