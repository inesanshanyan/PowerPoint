#pragma once

#include <unordered_map>
#include <string>
#include <vector>

class Command {
public:
    //virtual bool validate(const std::unordered_map<std::string, std::vector<std::string>>& options) = 0;
    virtual void execute() = 0;
    virtual ~Command() = default;
};

