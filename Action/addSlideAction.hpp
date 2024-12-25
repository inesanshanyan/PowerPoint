#pragma once

#include "IAction.hpp"
#include <memory>
#include "../Document/document.hpp"
#include <iostream>

class AddSlideAction : public IAction {
public:
    AddSlideAction() {}

    void execute(Document& document) override {
        document.addSlide();
        
        slideId = document.getSlideIdOfLastAdded();
        renderInfoBackup = document.getSlide(slideId)->getRenderInfos();

        std::cout << "Slide added with id: " << slideId << std::endl;
    }

    void undo(Document& document) override {
        if (slideId != -1) {
            auto slide = document.getSlide(slideId);
            if (slide) {
                renderInfoBackup = slide->getRenderInfos();
                document.removeSlide(slideId);
            }
            std::cout << "Undo: Slide removed with id: " << slideId << std::endl;
        }
    }

    void redo(Document& document) override {
        if (slideId != -1) {
            document.addSlide();  
            auto slide = document.getSlide(slideId);
            if (slide) {
                slide->setRenderInfos(renderInfoBackup);
                std::cout << "Redo: Slide added with id: " << slideId << std::endl;
            }
        }
    }

private:
    int slideId = -1;   
    std::vector<RenderInfo> renderInfoBackup;           
};
