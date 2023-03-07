#include "split.h"

std::vector<std::string> Split(const std::string& line, char delimiter) {
    std::vector<std::string> strings(0);
    int index = 0;
    std::string temp_line = line;
    while (index > -1) {
        index = temp_line.find(delimiter);
        strings.push_back(temp_line.substr(0, index));
        temp_line = temp_line.substr(index + 1, temp_line.size() - 1);
    }
    return strings;
}
