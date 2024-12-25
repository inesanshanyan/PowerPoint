#pragma once

#include "ICommand.hpp"
#include <iostream>

class UndoCommand : public ICommand { 
public:
    explicit UndoCommand(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) { }

    void execute(Editor& editor) override {
        editor.undo(); 
    }
};
