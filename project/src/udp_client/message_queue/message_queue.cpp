#include "message_queue.h"

#include "../constants.h"
#include "../message_data/message_data.h"

#include <mutex>
#include <iostream>

void parse_data(const MessageData& data);

void MessageQueue::push(const MessageData& data)
{
    std::unique_lock<std::mutex> guard {m_mutex};
    if (full())
        m_queue.pop();
    m_queue.push(data);
    // info();
    guard.unlock();
    m_var.notify_one();
}

MessageData MessageQueue::pop()
{
    std::unique_lock<std::mutex> guard {m_mutex};
    m_var.wait(guard, [this]() {return !empty();});
    MessageData data {m_queue.front()};
    m_queue.pop();
    info();
    return data;
}

bool MessageQueue::empty() const
{
    return m_queue.empty();
}

bool MessageQueue::full() const
{
    return m_queue.size() >= constants::queue_size;
}

void MessageQueue::info() const
{
    std::cout << "Queue size: " << m_queue.size() << "\n";
    // std::cout << "Oldest message: ";
    // parse_data(m_queue.front());
    // std::cout << "Newest message: ";
    // parse_data(m_queue.back());
}
