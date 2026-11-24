#ifndef MESSAGE_QUEUE
#define MESSAGE_QUEUE

#include "../message/message.hpp"

#include <condition_variable>
#include <mutex>
#include <optional>
#include <queue>

class MessageQueue
{
public:
    void push(const Message& message);
    std::optional<Message> pop();
    bool empty() const;

private:
    static constexpr int max_size {100};

    std::queue<Message> m_queue {};
    std::mutex m_mutex {};
    std::condition_variable m_cv {};
};

#endif
