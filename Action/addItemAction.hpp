#pragma once

#include "IAction.hpp"
#include <memory>
#include "../Document/document.hpp"

class AddItemAction : public IAction {
public:
    AddItemAction(int slideId, const std::shared_ptr<Item>& item)
        : slideId(slideId), item(item) {}

    void execute(Document& document) override {
        document.addItemToSlide(slideId, item);  
    }

    void undo(Document& document) override {
        //undoStack.push(action);
        document.removeItemFromSlide(slideId, item->getID());  
    }

    void redo(Document& document) override {
        execute(document);  
    }

private:
    int slideId;  
    std::shared_ptr<Item> item;  
};
