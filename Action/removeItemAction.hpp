#pragma once

#include "IAction.hpp"
#include <memory>
#include "../Document/document.hpp"

class RemoveItemAction : public IAction {
public:
    RemoveItemAction(int slideId, int itemId)
        : slideId(slideId), itemId(itemId) {}

    void execute(Document& document) override {
        document.removeItemFromSlide(slideId, itemId); 
    }

    void undo(Document& document) override {
        auto item = document.getSlide(slideId)->getItem(itemId);
        if (item) {
            document.addItemToSlide(slideId, item);
        }
    }

    void redo(Document& document) override {
        execute(document);  
    }

private:
    int slideId;
    int itemId;
};
