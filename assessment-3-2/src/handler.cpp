#include "handler.h"

#include <cstdio>
#include <iostream>
#include <string>

Handler::Handler(const std::string& path)
{
    file_ = std::fopen(path.c_str(), "w");
}

Handler::Handler(Handler&& other) noexcept
    : file_{other.file_}
{
    other.file_ = nullptr;
}

Handler& Handler::operator=(Handler&& other) noexcept
{
    if (this != &other)
    {
        file_ = other.file_;
        other.file_ = nullptr;
    }
    return *this;
}

Handler::~Handler()
{
    std::fclose(file_);
}

void Handler::write(const std::string& text)
{
    if (!file_)
        return;
    std::fprintf(file_, "%s\n", text.c_str());
}
