#include "Utils.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>

std::vector<std::string> utils::split(const std::string& toSeparate, char del) {
    std::vector<std::string> result;
    std::string curr = "";
    for (int i = 0; i < toSeparate.size(); i++) {
        if (toSeparate[i] == del) {
            if (curr != "") {
                result.push_back(curr);
                curr = "";
            }
        }
        else
            curr = curr + toSeparate[i];
    }
    if (curr != "")
        result.push_back(curr);
    return result;
}

bool utils::tryParseDouble(const std::string& s, double& out)
{
    try {
        size_t idx;
        out = std::stod(s, &idx);
        return idx == s.size();
    }
    catch (const std::invalid_argument&) {
        return false;
    }
}

std::string utils::doubleToString(double num)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << num;
    return oss.str();
}


