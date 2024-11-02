#include "circle.hpp"

Circle::Circle(const Position& pos, const std::string& color, const Size& size, const std::string& name) {
    set_pos(pos);
    set_color(color);
    set_size(size);
    set_name(name);
}

void Circle::set_pos(const Position& pos) {
    position = pos;
}

void Circle::set_color(const std::string& c) {
    color = c;
}

void Circle::set_index(std::size_t i) {
    index = i;
}

void Circle::set_size(const Size& s) {
    size = s;
}

void Circle::set_name(const std::string& n) {
    name = n;
}

Position Circle::get_pos() const {
    return position;
}

std::string Circle::get_color() const {
    return color;
}

std::size_t Circle::get_index() const {
    return index;
}

Size Circle::get_size() const {
    return size;
}

std::string Circle::get_name() const {
    return name;
}
