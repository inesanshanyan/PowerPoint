#pragma once

#include "ICommand.hpp"
#include "../Action/printSlideAction.hpp"
#include <unordered_map>
#include <variant>
#include <iostream>

class PrintSlideCommand : public ICommand {
public:
    explicit PrintSlideCommand(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options)
        : slideId(std::get<int>(options.at("-id")[0])) 
    {}

    void execute(Editor& editor) override {
        auto action = std::make_shared<PrintSlideAction>(slideId);

        editor.executeAction(action);

        std::cout << "Executed DrawSlideCommand for slide ID: " << slideId << "\n";
    }

private:
    int slideId;
};
