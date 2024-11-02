#pragma once

#include "command.hpp"
#include "../Document/slide_collection.hpp"

class ShowSlideCollection : public Command {
public:
    ShowSlideCollection(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {   }

    void execute() override {
        std::cout << "Executing ShowSlideCollection command." << std::endl;

        SlideCollection::get_instance().show();
    }

private:
};