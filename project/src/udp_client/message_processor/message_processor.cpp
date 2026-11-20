#include "message_processor.h"

#include "../message_queue/message_queue.h"

#include <iostream>
#include <thread>

void parse_data(const MessageData& data);

void process_message(MessageQueue& queue)
{
    while (running)
    {
        parse_data(queue.pop());
        // std::cout << "Thread: " << std::this_thread::get_id() << " (processor)\n";
    }
}

void parse_data(const MessageData& data);

ThreadHandler::~ThreadHandler()
{
    running = false;
    if (!m_thread.joinable())
        return;
    m_thread.join();
}

MessageProcessor::MessageProcessor(MessageQueue& queue)
    : m_queue {queue}, m_handler {[this]() {process_message(m_queue);}}
{
    
}
