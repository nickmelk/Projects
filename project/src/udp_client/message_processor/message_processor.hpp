#ifndef MESSAGE_PROCESSOR
#define MESSAGE_PROCESSOR

#include "../gen/schema.pb.h"
#include "../message/message.hpp"
#include "../message_queue/message_queue.hpp"
#include "../thread_handler/thread_handler.hpp"

#include <iostream>
#include <iomanip>

class MessageProcessor
{
public:
    MessageProcessor(MessageQueue& queue, const bool& status);
    void process(MessageQueue& queue, const bool& status) const;
    void parse_message(const Message& message) const;
    void parse_reading(const ReadingMessage& reading) const;
    template <typename T>
    void log(const T& reading, std::string_view message, std::size_t bytes) const;

private:
    ThreadHandler m_handler {};
};

template <typename T>
void MessageProcessor::log(const T& reading, std::string_view message, std::size_t bytes) const
{
    std::cout << "Received a packet: ";
    std::cout << std::setw(3) << bytes << 'B';
    std::cout << std::setw(10) << std::setprecision(3) << reading.value();
    std::cout << std::setw(25) << message << '\n';
}

#endif
