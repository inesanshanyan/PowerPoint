#pragma once

#include "ICommand.hpp"
#include <iostream>

class HelpCommand : public ICommand {
public:
    explicit HelpCommand(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {}

    void execute(Editor& editor) override {
        std::cout << "Available commands:\n";
        std::cout << "addItem -slideID -type string -pos double double -size double double -color string\n";
        std::cout << "removeItem -slideID int -id int\n";
        std::cout << "editItem -slideID int -id int -pos double double -size double double -color string\n";
        std::cout << "addSlide\n";
        std::cout << "removeSlide -id int\n";
        std::cout << "drawSlide -id int\n";
        std::cout << "help\n";
        std::cout << "exit\n";
    }
};
