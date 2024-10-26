#include "item_collection.hpp"

void ItemCollection::add_item(std::shared_ptr<Item> item) {
    items.push_back(item);
}

void ItemCollection::remove_item(std::size_t index) {
    if (index < items.size()) {
        items.erase(items.begin() + index);
    }
}

std::shared_ptr<Item> ItemCollection::get_item(std::size_t index) const {
    if (index < items.size()) {
        return items[index];
    }
    return nullptr;
}

std::size_t ItemCollection::size() const {
    return items.size();
}
