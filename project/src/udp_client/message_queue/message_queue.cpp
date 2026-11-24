#include "message_queue.hpp"

#include "../message/message.hpp"

#include <iostream>
#include <mutex>
#include <optional>

void MessageQueue::push(const Message& message)
{
    std::unique_lock<std::mutex> lock {m_mutex};
    if (m_queue.size() >= max_size)
        m_queue.pop();
    m_queue.push(message);
    lock.unlock();
    m_cv.notify_one();
}

std::optional<Message> MessageQueue::pop()
{
    std::unique_lock<std::mutex> lock {m_mutex};
    m_cv.wait(lock, [this]() {return !m_queue.empty();});
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
