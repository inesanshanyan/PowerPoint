#pragma once

#include "command.hpp"

class RemoveSlide : public Command {
public:
    RemoveSlide(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
        const auto& indexOptions = options.at("-index");
        index = std::get<int>(indexOptions[0]);
    }

    void execute() override {
        std::cout << "Executing RemoveSlide command." << std::endl;
        std::cout << "index: " << index << std::endl;

         if (index < 0) {
            throw std::invalid_argument("index < 0");
        }

        SlideCollection& collection = SlideCollection::get_instance();

        if (index >= collection.size()) {
            throw std::out_of_range("unable to remove the slide");
        }

        collection.remove_slide(index);

    }

private:
    int index;
};