#pragma once

#include "ICommand.hpp"
#include "../Action/addSlideAction.hpp"
#include "../Document/document.hpp"
#include <unordered_map>
#include <variant>
#include <iostream>

class AddSlideCommand : public ICommand {
public:
    explicit AddSlideCommand(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options)
        {}

    void execute(Editor& editor) override {
        auto action = std::make_shared<AddSlideAction>();
        editor.executeAction(action);

        std::cout << "Executed AddSlideCommand\n ";
    }

private:
    int slideId;
};
