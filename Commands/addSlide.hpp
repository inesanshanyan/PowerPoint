#pragma once

#include "command.hpp"
#include "../Document/slide_collection.hpp"

class AddSlide : public Command {
public:
    AddSlide(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
        const auto& indexOptions = options.at("-index");
        index = std::get<int>(indexOptions[0]);

        const auto& colorOptions = options.at("-color");
        color = std::get<std::string>(colorOptions[0]);
    }

    void execute() override {
        std::cout << "Executing AddSlide command." << std::endl;
        std::cout << "index: " << index << std::endl;

        if (index < 0) {
            throw std::invalid_argument("index < 0");
        }

    
        if (index >= SlideCollection::get_instance().size()) { // correct index insertion
            std::cout << "adding slide at the end" << std::endl;
        } else if (SlideCollection::get_instance().get_slide(index) != nullptr) {
            throw std::invalid_argument("the slide already exists");
        }

        auto slide = std::make_shared<Slide>(index, color);
        SlideCollection::get_instance().add_slide(slide);

    }

private:
    int index;
    std::string color;
};