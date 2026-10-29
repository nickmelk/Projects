#ifndef SIGNAL_VALIDATOR_H
#define SIGNAL_VALIDATOR_H

template <typename T, T Min, T Max>
class SignalValidator
{
public:
    bool validate(T value)
    {
        return value >= Min && value <= Max;
    }
};

#endif
