#pragma once

#include "./Items/item.hpp"
#include <unordered_map>
#include <memory>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class Slide {
public:
    Slide() {}

    void addItem(Shape shape, const Geometry& geometry, const Attribute& attribute);
    void removeItem(int itemId);
    std::shared_ptr<Item> getItem(int itemId);

    void editItem(int itemId, std::shared_ptr<Item> updatedItem);

    std::vector<RenderInfo> getRenderInfos() const;
    void setRenderInfos(const std::vector<RenderInfo>& renderInfos);

    std::string shapeToString(Shape shape) const;

private:
    std::unordered_map<int, std::shared_ptr<Item>> itemCollection;
    static int nextItemId;
    std::shared_ptr<Item> createItem(Shape shape, const Geometry& geometry, const Attribute& attribute);

    
};
