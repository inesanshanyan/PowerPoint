#pragma once

#include "ICommand.hpp"
#include "../Action/addItemAction.hpp"
#include "../Document/document.hpp"
#include <unordered_map>
#include <variant>
#include <iostream>

class AddItemCommand : public ICommand {
public:
    explicit AddItemCommand(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options)
        : slideId(std::get<int>(options.at("-slideID")[0])) 
    {
        std::string shapeType = std::get<std::string>(options.at("-type")[0]);

        if (shapeType == "rectangle") {
            shape = Shape::RECTANGLE;
        } else if (shapeType == "triangle") {
            shape = Shape::TRIANGLE;
        } else if (shapeType == "ellipse") {
            shape = Shape::ELLIPSE;
        } else {
            throw std::invalid_argument("Unknown shape type: " + shapeType);
        }

        if (options.find("-pos") != options.end()) {
            position = { std::get<double>(options.at("-pos")[0]), std::get<double>(options.at("-pos")[1]) };
        }
        if (options.find("-size") != options.end()) {
            size = { std::get<double>(options.at("-size")[0]), std::get<double>(options.at("-size")[1]) };
        }
        if (options.find("-color") != options.end()) {
            color = std::get<std::string>(options.at("-color")[0]);
        }
    }

    void execute(Editor& editor) override {
        Geometry geometry(position.first, position.second, size.first, size.second);
        Attribute attribute(color);
        std::shared_ptr<Item> item; 
        item = std::make_shared<Item>(itemId, shape, geometry, attribute);
        auto action = std::make_shared<AddItemAction>(slideId, item);
        editor.executeAction(action);

        std::cout << "Executed AddItemCommand \n";
    }

private:
    int slideId;
    int itemId;  
    Shape shape; 
    std::pair<double, double> position = {0, 0};  
    std::pair<double, double> size = {0, 0};      
    std::string color = "black";                  
};
