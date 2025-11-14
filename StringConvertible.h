#pragma once
#include "Figure.h"
#include <string>
#include <memory>

class StringConvertible {
public:
    virtual std::string to_string() const = 0;
    virtual ~StringConvertible() = default;
};