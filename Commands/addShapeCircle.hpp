#pragma once

#include "command.hpp"
#include "../Document/Items/circle.hpp"
#include "../Document/slide_collection.hpp"

class AddShapeCircle : public Command {
public:
    AddShapeCircle(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
        const auto& colorOptions = options.at("-color");
        color = std::get<std::string>(colorOptions[0]);

        const auto& sizeOptions = options.at("-size");
        radius = std::get<int>(sizeOptions[0]);

        const auto& posOptions = options.at("-pos");
        pos.x = std::get<int>(posOptions[0]);
        pos.y = std::get<int>(posOptions[1]);

        const auto& slideindex = options.at("-slideindex");
        slide_index = std::get<int>(slideindex[0]); 

    }

    void execute() override {
        std::cout << "Executing AddShapeCircle command." << std::endl;
        std::cout << "color: " << color << ", radius: " << radius 
                  << ", position: (" << pos.x << ", " << pos.y << ")" << std::endl;

        SlideCollection& collection = SlideCollection::get_instance();
        try {
            auto slide = collection.get_slide(slide_index);
            auto circle = std::make_shared<Circle>(pos, color, radius, "circle");
            slide->add_item(circle); 
            std::cout << "circle added to slide at index " << slide_index << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        
    }

private:
    std::string color;
    int radius;
    Position pos;
    int slide_index;
};