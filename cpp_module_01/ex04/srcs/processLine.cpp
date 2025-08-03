#include "../incs/processLine.hpp"

std::string process_line(char *argv[], const std::string &str)
{
    std::string to_replace = argv[2];
    std::string replacement = argv[3];
    std::string line = str;

    size_t index = line.find(to_replace);
    while (index != std::string::npos)
    {
        line = line.substr(0, index) + replacement + line.substr(index + to_replace.length());
        index = line.find(to_replace, index + replacement.length());
    }

    return line;
}