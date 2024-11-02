#pragma once

#include "command.hpp"

class AddText : public Command {
public:
    AddText(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
        const auto& textOptions = options.at("-text");
        text = std::get<std::string>(textOptions[0]);

        const auto& sizeOptions = options.at("-size");
        fontSize = std::get<int>(sizeOptions[0]);

        const auto& posOptions = options.at("-pos");
        x = std::get<int>(posOptions[0]);
        y = std::get<int>(posOptions[1]);
    }

    void execute() override {
        std::cout << "Executing AddShapeText command." << std::endl;
        std::cout << "text: " << text << ", font size: " << fontSize 
                  << ", position: (" << x << ", " << y << ")" << std::endl;
    }

private:
    std::string text;
    int fontSize;
    int x;
    int y;
};