#include "handler.h"

#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

Handler::Handler(const std::string& path)
{
    if (path.empty())
        throw std::invalid_argument("Empty path");
    file_ = std::fopen(path.c_str(), "w");
    if (!file_)
        throw std::runtime_error("Failed to open file");
}

Handler::Handler(Handler&& other) noexcept
    : file_{std::exchange(other.file_, nullptr)}
{

}

Handler& Handler::operator=(Handler&& other) noexcept
{
    if (this != &other)
    {
        close();
        file_ = other.file_;
        other.file_ = nullptr;
    }
    return *this;
}

Handler::~Handler()
{
    close();
}

void Handler::write(const std::string& text)
{
    if (!file_)
        return;
    std::fprintf(file_, "%s\n", text.c_str());
}

void Handler::close()
{
    if (!file_)
        return;
    std::fclose(file_);
    file_ = nullptr;
}
