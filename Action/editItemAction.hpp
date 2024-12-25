#pragma once

#include "IAction.hpp"
#include <memory>
#include "../Document/document.hpp"

class EditItemAction : public IAction {
public:
    EditItemAction(int slideId, int itemId, const std::shared_ptr<Item>& updatedItem)
        : slideId(slideId), itemId(itemId), updatedItem(updatedItem), originalItem(nullptr) {}

    void execute(Document& document) override {
        auto slide = document.getSlide(slideId);
        if (!slide) {
            throw std::runtime_error("Slide not found");
        }

        auto existingItem = slide->getItem(itemId);
        if (!existingItem) {
            throw std::runtime_error("Item not found");
        }

        originalItem = existingItem;

        document.editItemInSlide(slideId, itemId, updatedItem);
    }

    void undo(Document& document) override {
        if (!originalItem) {
            throw std::runtime_error("Original item not stored for undo");
        }
        document.editItemInSlide(slideId, itemId, originalItem);
        //editor.undo(EditItemAction);
    }

    void redo(Document& document) override {
        document.editItemInSlide(slideId, itemId, updatedItem);
    }

private:
    int slideId;
    int itemId;
    std::shared_ptr<Item> updatedItem;  
    std::shared_ptr<Item> originalItem;  
};
