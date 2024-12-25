#pragma once

#include "ICommand.hpp"
#include "../Action/removeItemAction.hpp"
#include "../Document/document.hpp"
#include <unordered_map>
#include <variant>
#include <iostream>

class RemoveItemCommand : public ICommand {
public:
    explicit RemoveItemCommand(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options)
        : slideId(std::get<int>(options.at("-slideID")[0])), 
          itemId(std::get<int>(options.at("-id")[0]))
    {}

    void execute(Editor& editor) override {
        auto action = std::make_shared<RemoveItemAction>(slideId, itemId);
        editor.executeAction(action);

        std::cout << "Executed RemoveItemCommand\n";
    }

private:
    int slideId;
    int itemId;
};
