#pragma once

#include "../Document/document.hpp"
#include "ICommand.hpp"
#include "../Action/drawSlideAction.hpp"
#include <unordered_map>
#include <variant>
#include <iostream>
#include <fstream>
#include "../Serialize/json.hpp"

using json = nlohmann::json;

class LoadSlideCommand : public ICommand {
public:
    explicit LoadSlideCommand(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options)
        : slideId(std::get<int>(options.at("-id")[0])) {}

    void execute(Editor& editor) override {
        std::ifstream file("savedSlide.json");
        if (!file.is_open()) {
            std::cout << "Slide file for ID " << slideId << " not found.\n";
            return;
        }

        json slideJson;
        file >> slideJson;
        file.close();

        auto newSlide = std::make_shared<Slide>();
        for (const auto& itemJson : slideJson["items"]) {
            Shape shape;
            std::string shapeStr = itemJson["shape"];
            if (shapeStr == "Rectangle") shape = Shape::RECTANGLE;
            else if (shapeStr == "Triangle") shape = Shape::TRIANGLE;
            else if (shapeStr == "Ellipse") shape = Shape::ELLIPSE;
            else throw std::runtime_error("Unknown shape: " + shapeStr);

            Geometry geometry(itemJson["x"], itemJson["y"], itemJson["width"], itemJson["height"]);
            Attribute attribute = Attribute::fromJson(itemJson["attribute"]);

            newSlide->addItem(shape, geometry, attribute);
        }

        editor.getDocument()->addSlide();
        int newSlideId = editor.getDocument()->getSlideIdOfLastAdded();
        editor.getDocument()->getSlide(newSlideId) = newSlide;

        std::cout << "Loaded data into new slide with ID: " << newSlideId << "\n";
        std::cout << "Slide contents: \n";
        for (const auto& renderInfo : newSlide->getRenderInfos()) {
            std::cout << "Shape: " << newSlide->shapeToString(renderInfo.shape) 
                      << ", Position: (" << renderInfo.x << ", " << renderInfo.y << ")" 
                      << ", Size: (" << renderInfo.width << " x " << renderInfo.height << ")" 
                      << ", Color: " << renderInfo.attribute.getColor() << "\n";
        }
    }

private:
    int slideId;
};
