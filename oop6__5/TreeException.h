#pragma once
#include <stdexcept>
#include <string>

class TreeException : public std::runtime_error {
public:
    explicit TreeException(const std::string& message) : std::runtime_error(message) {}
};