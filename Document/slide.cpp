#include "slide.hpp"

Slide::Slide(int i, const std::string& c) :  color(c) { }

void Slide::set_color(const std::string& c) {
    color = c;
}

void Slide::add_item(std::shared_ptr<Item> item) {
    items.add_item(item);
}

void Slide::remove_item(std::size_t index) {
    items.remove_item(index);
}

std::shared_ptr<Item> Slide::get_item(std::size_t index) const {
    return items.get_item(index);
}

std::size_t Slide::item_count() const {
    return items.size();
}
