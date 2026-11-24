#include "thread_handler.hpp"

#include <utility>

ThreadHandler::ThreadHandler(ThreadHandler&& other) noexcept
    : m_thread {std::move(other.m_thread)}
{

}

ThreadHandler& ThreadHandler::operator=(ThreadHandler&& other) noexcept
{
    if (this != &other)
        std::swap(m_thread, other.m_thread);
    return *this;
}

ThreadHandler::~ThreadHandler()
{
    if (m_thread.joinable())
        m_thread.join();
}
