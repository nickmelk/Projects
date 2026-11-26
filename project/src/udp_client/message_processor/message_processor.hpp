#ifndef MESSAGE_PROCESSOR
#define MESSAGE_PROCESSOR

#include "../gen/schema.pb.h"
#include "../message/message.hpp"
#include "../message_queue/message_queue.hpp"
#include "../thread_handler/thread_handler.hpp"

#include <atomic>
#include <condition_variable>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <string_view>

class MessageProcessor
{
public:
    void start(const std::atomic_bool& is_running);
    void enqueue(const Message& message);
    void process_message(const std::atomic_bool& status);
    void stop();

private:
    void parse_message(const Message& message) const;
    void parse_reading(const ReadingMessage& reading) const;

    MessageQueue m_queue {};
    std::mutex m_mutex {};
    std::condition_variable m_cv {};
    ThreadHandler m_handler {};
};

template <typename T>
void log(const T& reading, std::string_view message, std::size_t bytes)
{
    std::cout << "Received a packet: ";
    std::cout << std::setw(3) << bytes << 'B';
    std::cout << std::setw(10) << std::setprecision(3) << reading.value();
    std::cout << std::setw(25) << message << '\n';
}

#endif
