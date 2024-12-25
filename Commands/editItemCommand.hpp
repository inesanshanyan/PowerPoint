#pragma once

#include "ICommand.hpp"
#include "../Action/editItemAction.hpp"
#include <optional>
#include <unordered_map>
#include <variant>
#include <iostream>
class EditItemCommand : public ICommand {
public:
    explicit EditItemCommand(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options)
        : slideId(std::get<int>(options.at("-slideID")[0])),
          itemId(std::get<int>(options.at("-id")[0])) 
    {
        
        if (options.find("-pos") != options.end()) {
            pos = { std::get<double>(options.at("-pos")[0]), std::get<double>(options.at("-pos")[1]) };
        }
        if (options.find("-size") != options.end()) {
            size = { std::get<double>(options.at("-size")[0]), std::get<double>(options.at("-size")[1]) };
        }
        if (options.find("-color") != options.end()) {
            color = std::get<std::string>(options.at("-color")[0]);
        }
    }

    ~EditItemCommand() override = default;

    void execute(Editor& editor) override {
        
        Document doc;
        auto existingItem = editor.getDocument()->getSlide(slideId)->getItem(itemId);

        if (!existingItem) {
            std::cerr << "Item with ID " << itemId << " not found on slide " << slideId << "\n";
            return;
        }

        Shape shape = existingItem->getShape(); 
        Geometry updatedGeometry(0, 0, 0, 0); 
        if (pos && size) {
            updatedGeometry = Geometry(pos->first, pos->second, size->first, size->second);
        }

        Attribute updatedAttribute(color.value_or("black"));  


        auto updatedItem = std::make_shared<Item>(itemId, shape, updatedGeometry, updatedAttribute);
        auto action = std::make_shared<EditItemAction>(slideId, itemId, updatedItem);
        editor.executeAction(action);

        std::cout << "Executed EditItemCommand\n";
    }

private:
    int slideId;
    int itemId;
    std::optional<std::pair<double, double>> pos;  
    std::optional<std::pair<double, double>> size; 
    std::optional<std::string> color;            
};

