#ifndef THREAD_HANDLER
#define THREAD_HANDLER

#include <thread>

class ThreadHandler
{
public:
    template <typename... Args>
    explicit ThreadHandler(Args&&... args);
    ThreadHandler(const ThreadHandler& other) = delete;
    ThreadHandler& operator=(const ThreadHandler& other) = delete;
    ThreadHandler(ThreadHandler&& other) noexcept;
    ThreadHandler& operator=(ThreadHandler&& other) noexcept;
    ~ThreadHandler();

private:
    std::thread m_thread {};
};

template <typename... Args>
ThreadHandler::ThreadHandler(Args&&... args)
    : m_thread {std::forward<Args>(args)...}
{

}

#endif
