#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <variant>
#include <iostream>

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};



