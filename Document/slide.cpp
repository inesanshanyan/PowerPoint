#include "slide.hpp"

Slide::Slide(int i, const std::string& c) :  color(c) { }

void Slide::set_color(const std::string& c) {
    color = c;
}

std::string Slide::get_color() const {
    return color;
}

void Slide::set_index(const int& i) {
    index = i;
}

int Slide::get_index() const {
    return index;
}


void Slide::add_item(std::shared_ptr<Item> item) {
    items.add_item(item);
}

void Slide::remove_item(std::size_t index) {
    items.remove_item(index);
}

void Slide::show_items(){
    items.show();
}

std::shared_ptr<Item> Slide::get_item(std::size_t index) const {
    return items.get_item(index);
}

std::size_t Slide::item_count() const {
    return items.size();
}
