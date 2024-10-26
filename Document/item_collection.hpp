#pragma once

#include "Items/item.hpp"  

#include <vector>
#include <memory>

class ItemCollection {
public:
    void add_item(std::shared_ptr<Item> item);
    void remove_item(std::size_t index);
    std::shared_ptr<Item> get_item(std::size_t index) const;
    std::size_t size() const;

private:
    std::vector<std::shared_ptr<Item>> items;  
};
