#pragma once

#include "command.hpp"

class Help : public Command {
public:
    Help(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {   }
    void execute() override {
        std::cout << "Executing Help command." << std::endl;
    }
};