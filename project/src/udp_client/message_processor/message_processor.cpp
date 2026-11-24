#include "message_processor.hpp"

#include "../constants.hpp"
#include "../gen/schema.pb.h"
#include "../message/message.hpp"
#include "../message_queue/message_queue.hpp"

#include <functional>
#include <iostream>
#include <optional>

MessageProcessor::MessageProcessor(MessageQueue& queue, const bool& status)
    : m_handler {&MessageProcessor::process, this, std::ref(queue), std::ref(status)}
{

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

void MessageProcessor::process(MessageQueue& queue, const bool& status) const
{
    while (status)
    {
        if (std::optional<Message> message {queue.pop()}; message)
            parse_message(*message);
    }
}
