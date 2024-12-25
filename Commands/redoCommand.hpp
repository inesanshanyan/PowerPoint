#pragma once

#include "ICommand.hpp"
#include <iostream>

class RedoCommand : public ICommand { 
public:
    explicit RedoCommand(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) { }

    void execute(Editor& editor) override {
        std::cout << "Executed UndoCommand\n";
        editor.redo();  
    }
};
