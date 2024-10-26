#pragma once

#include "command.hpp"

class AddShapeSquare : public Command {
public:
    AddShapeSquare(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
        const auto& colorOptions = options.at("-color");
        color = std::get<std::string>(colorOptions[0]);

        const auto& sizeOptions = options.at("-size");
        sideLength = std::get<int>(sizeOptions[0]);

        const auto& posOptions = options.at("-pos");
        x = std::get<int>(posOptions[0]);
        y = std::get<int>(posOptions[1]);
    }

    void execute() override {
        std::cout << "Executing AddShapeSquare command." << std::endl;
        std::cout << "Color: " << color << ", Side Length: " << sideLength 
                  << ", Position: (" << x << ", " << y << ")" << std::endl;
    }

private:
    std::string color;
    int sideLength;
    int x;
    int y;
};