#include "circle.hpp"

Circle::Circle(int r) {
    size = r;
}

void Circle::set_pos(const Position& pos) {
    position = pos;
}

void Circle::set_color(const Color& c) {
    color = c;
}

void Circle::set_index(std::size_t i) {
    index = i;
}

void Circle::set_size(const Size& s) {
    size = s;
}

Position Circle::get_pos() const {
    return position;
}

Color Circle::get_color() const {
    return color;
}

std::size_t Circle::get_index() const {
    return index;
}

Size Circle::get_size() const {
    return size;
}
