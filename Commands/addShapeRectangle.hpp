#pragma once

#include "command.hpp"
#include "../Document/Items/rectangle.hpp"
#include "../Document/slide_collection.hpp"

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
        pos.x = std::get<int>(posOptions[0]); 
        pos.y = std::get<int>(posOptions[1]); 

        const auto& slideindex = options.at("-slideindex");
        slide_index = std::get<int>(slideindex[0]); 
    }

    void execute() override {
        std::cout << "Executing AddShapeRectangle command." << std::endl;
        std::cout << "color: " << color << ", width: " << width << ", height: " << height 
                  << ", pos: (" << pos.x << ", " << pos.y << ")" << std::endl;

        SlideCollection& collection = SlideCollection::get_instance();
        try {
            auto slide = collection.get_slide(slide_index);
            auto circle = std::make_shared<Circle>(pos, color, std::make_pair(width, height), "rectangle");
            slide->add_item(circle); 
            std::cout << "rectangle added to slide at index " << slide_index << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

private:
    std::string color;
    int width = 0;  
    int height = 0;  
    Position pos;   
    int slide_index;   
};
