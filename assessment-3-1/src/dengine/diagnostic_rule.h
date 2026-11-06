#ifndef DIAGNOSTIC_RULE_H
#define DIAGNOSTIC_RULE_H

#include "logger_interface.h"

template <typename Pred>
class DiagnosticRule
{
public:
    explicit DiagnosticRule(int id, Pred pred, std::string_view message,
        LoggerInterface& logger);

    std::string_view message() const;
    LoggerInterface& logger() const;
    template <typename T>
    bool evaluate(T value) const;
private:
    int m_id {};
    Pred m_pred {};
    std::string_view m_message {};
    LoggerInterface& m_logger {logging::c_logger};
};

template <typename Pred>
DiagnosticRule<Pred>::DiagnosticRule(int id, Pred pred,
    std::string_view message, LoggerInterface& logger)
    : m_id {id}, m_pred {pred}, m_message {message}, m_logger {logger}
{

}

template <typename Pred>
std::string_view DiagnosticRule<Pred>::message() const
{
    return m_message;
}

template <typename Pred>
LoggerInterface& DiagnosticRule<Pred>::logger() const
{
    return m_logger;
}

template <typename Pred>
template <typename T>
bool DiagnosticRule<Pred>::evaluate(T value) const
{
    return m_pred(value);
}

class RuleGenerator
{
public:
    template <typename Pred>
    DiagnosticRule<Pred> generate(Pred pred, std::string_view message,
        LoggerInterface& logger = logging::c_logger);
private:
    int m_id_counter {0};
};

template <typename Pred>
DiagnosticRule<Pred> RuleGenerator::generate(Pred pred,
    std::string_view message, LoggerInterface& logger)
{
    DiagnosticRule rule {m_id_counter, pred, message, logger};
    ++m_id_counter;
    return rule;
}

#endif
