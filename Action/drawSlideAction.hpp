#pragma once

#include "IAction.hpp"
#include <iostream>

class DrawSlideAction : public IAction {
public:
    DrawSlideAction(int slideId)
        : slideId(slideId) {}

    void execute(Document& document) {
        auto slide = document.getSlide(slideId);
        if (!slide) {
            throw std::runtime_error("Slide not found");
        }

        auto renderInfos = slide->getRenderInfos();
        View& view = View::getInstance();
        view.clearWindow();
        view.draw(renderInfos);

        for (const auto& renderInfo : renderInfos) {
            std::cout << "Drawing Item "
                    << " Shape: " << slide->shapeToString(renderInfo.shape)
                    << " X: " << renderInfo.x << " Y: " << renderInfo.y
                    << " Width: " << renderInfo.width << " Height: " << renderInfo.height
                    << " Color: " << renderInfo.attribute.getColor() << std::endl;
        }
    }

    void undo(Document& document) override {
        execute(document); 
    }

    void redo(Document& document) override {
        execute(document);
    }

private:
    int slideId;
};
