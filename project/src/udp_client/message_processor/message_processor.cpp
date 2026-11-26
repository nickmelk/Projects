#include "message_processor.hpp"

#include "../constants.hpp"
#include "../gen/schema.pb.h"
#include "../message/message.hpp"
#include "../thread_handler/thread_handler.hpp"

#include <atomic>
#include <functional>
#include <iostream>
#include <mutex>
#include <optional>

void MessageProcessor::start(const std::atomic_bool& is_running)
{
    m_handler = ThreadHandler {&MessageProcessor::process_message, this,
        std::cref(is_running)};
}

void MessageProcessor::enqueue(const Message& message)
{
    std::unique_lock<std::mutex> lock {m_mutex};
    m_queue.push(message);
    lock.unlock();
    m_cv.notify_one();
}

void MessageProcessor::process_message(const std::atomic_bool& is_running)
{
    while (is_running)
    {
        std::unique_lock<std::mutex> lock {m_mutex};
        m_cv.wait(lock, [this, &is_running]() {return !m_queue.empty() ||
            !is_running;});
        std::optional<Message> message {m_queue.pop()};
        lock.unlock();
        if (message)
            parse_message(*message);
    }
}

void MessageProcessor::stop()
{
    m_cv.notify_one();
}

void MessageProcessor::parse_message(const Message& message) const
{
    ReadingMessage reading {};
    if (reading.ParseFromArray(message.buffer.data(), message.bytes))
        parse_reading(reading);
    else
        std::cerr << "Failed to parse a message\n";
}

void MessageProcessor::parse_reading(const ReadingMessage& reading) const
{
    switch (reading.reading_case())
    {
    case ReadingMessage::kTemperatureReading:
        log(reading.temperature_reading(), reading.message(),
            reading.ByteSizeLong());
        break;
    case ReadingMessage::kRpmReading:
        log(reading.rpm_reading(), reading.message(),
            reading.ByteSizeLong());
        break;
    case ReadingMessage::kVoltageReading:
        log(reading.voltage_reading(), reading.message(),
            reading.ByteSizeLong());
        break;
    case ReadingMessage::kSpeedReading:
        log(reading.speed_reading(), reading.message(),
            reading.ByteSizeLong());
        break;
    default:
        log(reading.temperature_reading(), constants::unknown_reading,
            reading.ByteSizeLong());
        break;
    }
}
