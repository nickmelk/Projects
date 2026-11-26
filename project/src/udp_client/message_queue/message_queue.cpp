#include "message_queue.hpp"

#include "../message/message.hpp"

#include <iostream>
#include <optional>

void MessageQueue::push(const Message& message)
{
    if (m_queue.size() >= max_size)
        m_queue.pop();
    m_queue.push(message);
}

std::optional<Message> MessageQueue::pop()
{
    if (!m_queue.size())
    {
        std::cerr << "Queue is empty\n";
        return std::nullopt;
    }
    Message message {m_queue.front()};
    m_queue.pop();
    return message;
}

bool MessageQueue::empty() const
{
    return m_queue.empty();
}
