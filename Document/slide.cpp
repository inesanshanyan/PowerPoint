#include "slide.hpp"
#include "./Items/item.hpp"

#include <unordered_map>
#include <memory>
#include <iostream>

int Slide::nextItemId = 1;

void Slide::addItem(Shape shape, const Geometry& geometry, const Attribute& attribute) {
    auto item = createItem(shape, geometry, attribute);
    int itemId = ++nextItemId;
    item->setID(itemId);
    itemCollection[item->getID()] = item;
    std::cout << "Item added with id: " << itemId << "\n";
}

void Slide::removeItem(int itemId) {
    auto it = itemCollection.find(itemId);
    if (it != itemCollection.end()) {
        itemCollection.erase(it);
        std::cout << "Item with ID " << itemId << " removed.\n";
    } else {
        std::cout << "Item with ID " << itemId << " not found.\n";
    }
}


std::shared_ptr<Item> Slide::getItem(int itemId) {
    auto it = itemCollection.find(itemId);
    if (it != itemCollection.end()) {
        return it->second;
    }
    return nullptr;
}

void Slide::editItem(int itemId, std::shared_ptr<Item> updatedItem) {
    itemCollection[itemId] = updatedItem;
}

std::vector<RenderInfo> Slide::getRenderInfos() const {
    std::vector<RenderInfo> renderInfos;
    for (const auto& pair : itemCollection) {
        renderInfos.push_back(pair.second->getRenderInfo());
    }
    return renderInfos;
}


std::shared_ptr<Item> Slide::createItem(Shape shape, const Geometry& geometry, const Attribute& attribute) {
    return std::make_shared<Item>(nextItemId++, shape, geometry, attribute);
}


std::string Slide::shapeToString(Shape shape) const {
    switch (shape) {
        case Shape::RECTANGLE: return "Rectangle";
        case Shape::TRIANGLE: return "Triangle";
        case Shape::ELLIPSE: return "Ellipse";
        default: return "Unknown";
    }
}

void Slide::setRenderInfos(const std::vector<RenderInfo>& renderInfos) {
        int index = 0;
        for (auto& itemPair : itemCollection) {
            if (index < renderInfos.size()) {
                itemPair.second->setRenderInfo(renderInfos[index]);
                index++;
            }
        }
    }