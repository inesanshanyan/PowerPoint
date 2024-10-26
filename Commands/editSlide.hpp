#pragma once

#include "command.hpp"


class EditSlide : public Command {
public:
    EditSlide(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
        const auto& indexOptions = options.at("-index");
        index = std::get<int>(indexOptions[0]);

        const auto& colorOptions = options.at("-color");
        color = std::get<std::string>(colorOptions[0]);
    }

    void execute() override {
        std::cout << "Executing EditSlide command." << std::endl;
        std::cout << "Index: " << index << ", Color: " << color << std::endl;
    }

private:
    int index;
    std::string color;
};