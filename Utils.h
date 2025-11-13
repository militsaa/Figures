#pragma once
#include <vector>
#include <string>
namespace utils {
    std::vector<std::string> split(const std::string& toSeparate, char del);
    bool tryParseDouble(const std::string& s, double& out);
};
