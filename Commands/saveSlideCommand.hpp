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

class SaveSlideCommand : public ICommand {
public:
    explicit SaveSlideCommand(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options)
        : slideId(std::get<int>(options.at("-id")[0])) { }

    void execute(Editor& editor) override {
        auto slide = editor.getDocument()->getSlide(slideId);
        if (!slide) {
            std::cout << "Slide with ID " << slideId << " not found.\n";
            return;
        }

        json slideJson;
        slideJson["id"] = slideId;
        slideJson["items"] = json::array();

        for (const auto& renderInfo : slide->getRenderInfos()) {
            json itemJson;
            itemJson["shape"] = slide->shapeToString(renderInfo.shape);
            itemJson["x"] = renderInfo.x;
            itemJson["y"] = renderInfo.y;
            itemJson["width"] = renderInfo.width;
            itemJson["height"] = renderInfo.height;
            itemJson["attribute"] = renderInfo.attribute.toJson();
            slideJson["items"].push_back(itemJson);
        }

        std::ofstream file("savedSlide.json");
        if (file.is_open()) {
            file << slideJson.dump(4);
            file.close();
            std::cout << "Slide " << slideId << " saved successfully.\n";
        } else {
            std::cout << "Failed to save slide " << slideId << ".\n";
        }
    }

private:
    int slideId;
};
