#ifndef MESSAGE_PROCESSOR
#define MESSAGE_PROCESSOR

#include "../message_queue/message_queue.h"

#include <thread>

inline bool running {true};

class ThreadHandler
{
public:
    ThreadHandler() = default;
    template <typename Callable>
    ThreadHandler(Callable task);
    ThreadHandler(const ThreadHandler& other) = delete;
    ThreadHandler& operator=(const ThreadHandler& other) = delete;
    ThreadHandler(ThreadHandler&& other) = default;
    ThreadHandler& operator=(ThreadHandler&& other) = default;
    ~ThreadHandler();

private:
    std::thread m_thread {};
};

template <typename Callable>
ThreadHandler::ThreadHandler(Callable task)
    : m_thread {task}
{

}

class MessageProcessor
{
public:
    MessageProcessor(MessageQueue& queue);

private:
    MessageQueue& m_queue;
    ThreadHandler m_handler {};
};

#endif
