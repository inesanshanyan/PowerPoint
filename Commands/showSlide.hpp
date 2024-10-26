#pragma once

#include "command.hpp"

class ShowSlide : public Command {
public:
    ShowSlide(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
        const auto& indexOptions = options.at("-index");
        index = std::get<int>(indexOptions[0]);
    }

    void execute() override {
        std::cout << "Executing ShowSlide command." << std::endl;
        std::cout << "Index: " << index << std::endl;
    }

private:
    int index;
};