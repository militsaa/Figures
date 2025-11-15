#pragma once
#include <string>

class StringConvertible {
public:
    virtual std::string to_string() const = 0;
    virtual ~StringConvertible() = default;
};