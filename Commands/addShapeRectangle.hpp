#pragma once

#include "command.hpp"

class AddShapeRectangle : public Command {
public:
    AddShapeRectangle(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
        std::cout << "Created AddShapeRectangle command" << std::endl;

        const auto& colorOptions = options.at("-color");
        color = std::get<std::string>(colorOptions[0]); 

        const auto& sizeOptions = options.at("-size");
        width = std::get<int>(sizeOptions[0]);   
        height = std::get<int>(sizeOptions[1]);  

        const auto& posOptions = options.at("-pos");
        x = std::get<int>(posOptions[0]); 
        y = std::get<int>(posOptions[1]); 
    }

    void execute() override {
        std::cout << "Executing AddShapeRectangle command." << std::endl;
        std::cout << "color: " << color << ", width: " << width << ", height: " << height 
                  << ", pos: (" << x << ", " << y << ")" << std::endl;

    }

private:
    std::string color;
    int width = 0;  
    int height = 0;  
    int x = 0;      
    int y = 0;       
};
