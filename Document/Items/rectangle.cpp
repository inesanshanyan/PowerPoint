#include "rectangle.hpp"

Rectangle::Rectangle(int width, int height) {
    size = std::make_pair(width, height);
}

void Rectangle::set_pos(const Position& pos) {
    position = pos;
}

void Rectangle::set_color(const Color& c) {
    color = c;
}

void Rectangle::set_index(std::size_t i) {
    index = i;
}

void Rectangle::set_size(const Size& s) {
    size = s;
}

Position Rectangle::get_pos() const {
    return position;
}

Color Rectangle::get_color() const {
    return color;
}

std::size_t Rectangle::get_index() const {
    return index;
}

Size Rectangle::get_size() const {
    return size;
}
