#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>

class FileHandler
{
public:
    explicit FileHandler(const char* log_file);
    FileHandler(const FileHandler& other) = delete;
    FileHandler& operator=(const FileHandler& other) = delete;
    FileHandler(FileHandler&& other) noexcept;
    FileHandler& operator=(FileHandler&& other) noexcept;
    ~FileHandler() = default;

    std::ofstream& log_file();

private:
    std::ofstream m_log_file {};
};

#endif
