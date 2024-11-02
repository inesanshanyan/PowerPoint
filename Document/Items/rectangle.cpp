#include "rectangle.hpp"

Rectangle::Rectangle(const Position& pos, const std::string& color, const Size& size, const std::string& name) {
    set_pos(pos);
    set_color(color);
    set_size(size);
    set_name(name);
}

void Rectangle::set_pos(const Position& pos) {
    position = pos;
}

void Rectangle::set_color(const std::string& c) {
    color = c;
}

void Rectangle::set_index(std::size_t i) {
    index = i;
}

void Rectangle::set_size(const Size& s) {
    size = s;
}

void Rectangle::set_name(const std::string& n) {
    name = n;
}

Position Rectangle::get_pos() const {
    return position;
}

std::string Rectangle::get_color() const {
    return color;
}

std::size_t Rectangle::get_index() const {
    return index;
}

Size Rectangle::get_size() const {
    return size;
}

std::string Rectangle::get_name() const {
    return name;
}

