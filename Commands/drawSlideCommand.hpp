#pragma once

#include "ICommand.hpp"
#include "../Action/drawSlideAction.hpp"
#include <unordered_map>
#include <variant>
#include <iostream>

class DrawSlideCommand : public ICommand {
public:
    explicit DrawSlideCommand(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options)
        : slideId(std::get<int>(options.at("-id")[0])) 
    {}

    void execute(Editor& editor) override {
        auto action = std::make_shared<DrawSlideAction>(slideId);

        editor.executeAction(action);

        std::cout << "Executed DrawSlideCommand for slide ID: " << slideId << "\n";
    }

private:
    int slideId;
};
