#pragma once

#include "command.hpp"

class Play : public Command {
public:
    Play(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& data) {
        //std::cout << "play command constuctor";
    }
    void execute() override {
        std::cout << "Executing Play command." << std::endl;
    }
};