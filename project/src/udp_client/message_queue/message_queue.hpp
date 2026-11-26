#ifndef MESSAGE_QUEUE
#define MESSAGE_QUEUE

#include "../message/message.hpp"

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
};

#endif
