#include "Utils.h"

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
