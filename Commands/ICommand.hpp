#pragma once

#include "../Editor/editor.hpp"
#include "iostream"
#include "../CLI/Parser/command_struct.hpp"

class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void execute(Editor& editor) = 0;
};
