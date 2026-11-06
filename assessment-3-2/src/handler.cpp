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
        std::swap(file_, other.file_);
    return *this;
}

Handler::~Handler()
{
    if (file_)
    {
        std::fclose(file_);
        file_ = nullptr;
    }
}

std::FILE* Handler::file() const
{
    return file_;
}

FileWriter::FileWriter(Handler&& handler)
    : m_handler {std::move(handler)}
{

}

void FileWriter::write(const std::string& text) const
{
    std::fprintf(m_handler.file(), "%s\n", text.c_str());
}
