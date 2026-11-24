#ifndef HANDLER_H
#define HANDLER_H

#include <cstdio>
#include <string>

class Handler final
{
public:
    explicit Handler(const std::string& path);
    Handler(const Handler& other) = delete;
    Handler& operator=(const Handler& other) = delete;
    Handler(Handler&& other) noexcept;
    Handler& operator=(Handler&& other) noexcept;
    ~Handler();

    std::FILE* file() const;

private:
    std::FILE* file_ {nullptr};
};

class FileWriter
{
public:
    explicit FileWriter(Handler&& handler);
    void write(const std::string& text) const;

private:
    Handler m_handler {"test.txt"};
};

#endif
