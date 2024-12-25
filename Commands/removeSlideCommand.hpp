#pragma once

#include "ICommand.hpp"
#include "../Action/removeSlideAction.hpp"
#include "../Document/document.hpp"
#include <unordered_map>
#include <variant>
#include <iostream>

class RemoveSlideCommand : public ICommand {
public:
    explicit RemoveSlideCommand(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options)
        : slideId(std::get<int>(options.at("-id")[0]))
    {}

    void execute(Editor& editor) override {
        auto action = std::make_shared<RemoveSlideAction>(slideId);
        editor.executeAction(action);

        std::cout << "Executed RemoveSlideCommand\n";
    }

private:
    int slideId;
};
