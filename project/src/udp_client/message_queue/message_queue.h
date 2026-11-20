#ifndef MESSAGE_QUEUE
#define MESSAGE_QUEUE

#include "../message_data/message_data.h"

#include <condition_variable>
#include <mutex>
#include <queue>

class MessageQueue
{
public:
    const std::condition_variable& var() const;
    void push(const MessageData& data);
    MessageData pop();
    bool empty() const;
    bool full() const;
    void info() const;

private:
    std::queue<MessageData> m_queue {};
    std::mutex m_mutex {};
    std::condition_variable m_var {};
};

#endif
