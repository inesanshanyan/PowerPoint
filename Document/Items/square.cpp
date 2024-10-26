#include "square.hpp"

Square::Square(int s) {
    size = s;
}

void Square::set_pos(const Position& pos) {
    position = pos;
}

void Square::set_color(const Color& c) {
    color = c;
}

void Square::set_index(std::size_t i) {
    index = i;
}

void Square::set_size(const Size& s) {
    size = s;
}

Position Square::get_pos() const {
    return position;
}

Color Square::get_color() const {
    return color;
}

std::size_t Square::get_index() const {
    return index;
}

Size Square::get_size() const {
    return size;
}
