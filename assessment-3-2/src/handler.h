#ifndef HANDLER_H
#define HANDLER_H

#include <cstdio>
#include <string>

class Handler
{
public:
    explicit Handler(const std::string& path);
    Handler(const Handler& other) = delete;
    Handler& operator=(const Handler& other) = delete;
    Handler(Handler&& other) noexcept;
    Handler& operator=(Handler&& other) noexcept;
    ~Handler();

    void write(const std::string& text);
    void close();

private:
    std::FILE* file_ {nullptr};
};

#endif
