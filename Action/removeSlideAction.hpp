#pragma once

#include "IAction.hpp"
#include <memory>
#include "../Document/document.hpp"
#include <iostream>
#include <unordered_map>
#include "../Document/document.hpp"

class RemoveSlideAction : public IAction {
public:
    RemoveSlideAction(int slideId)
        : slideId(slideId) {}

    void execute(Document& document) override {
        auto slide = document.getSlide(slideId);
        if (slide) {
            removedSlideId = slideId;
            backupSlideItems = slide->getRenderInfos();
            document.removeSlide(slideId); 
            std::cout << "Slide " << slideId << " removed.\n";
        }
    }

    void undo(Document& document) override {
        if (removedSlideId != -1 && !backupSlideItems.empty()) {
            // Backup before adding back the slide (to avoid overwriting)
            document.addSlide();
            auto restoredSlide = document.getSlide(document.getSlideIdOfLastAdded());
            if (restoredSlide) {
                for (const auto& renderInfo : backupSlideItems) {
                    restoredSlide->addItem(renderInfo.shape, 
                                            Geometry(renderInfo.x, renderInfo.y, renderInfo.width, renderInfo.height), 
                                            renderInfo.attribute);
                }
                std::cout << "Slide " << removedSlideId << " restored with items.\n";
            }
        }
    }

    void redo(Document& document) override {
        execute(document);  
    }

private:
    int slideId;              
    int removedSlideId = -1;   
    std::vector<RenderInfo> backupSlideItems; 
};
