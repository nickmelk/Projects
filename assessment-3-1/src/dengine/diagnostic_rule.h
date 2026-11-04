#ifndef DIAGNOSTIC_RULE_H
#define DIAGNOSTIC_RULE_H

template <typename Pred>
class DiagnosticRule
{
public:
    DiagnosticRule(int id, Pred pred, std::string_view message);
    std::string_view message() const;
    template <typename T>
    bool evaluate(T value);
private:
    int m_id {};
    Pred m_pred {};
    std::string_view m_message {};
};

template <typename Pred>
template <typename T>
bool DiagnosticRule<Pred>::evaluate(T value)
{
    return m_pred(value);
}

template <typename Pred>
std::string_view DiagnosticRule<Pred>::message() const
{
    return m_message;
}

template <typename Pred>
DiagnosticRule<Pred>::DiagnosticRule(int id, Pred pred,
    std::string_view message)
    : m_id {id}, m_pred {pred}, m_message {message}
{

}

class RuleGenerator
{
public:
    template <typename Pred>
    DiagnosticRule<Pred> generate(Pred pred, std::string_view message);
private:
    int m_id_counter {0};
};

template <typename Pred>
DiagnosticRule<Pred> RuleGenerator::generate(Pred pred,
    std::string_view message)
{
    DiagnosticRule rule {m_id_counter, pred, message};
    ++m_id_counter;
    return rule;
}

#endif
