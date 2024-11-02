// text.cpp
#include "text.hpp"

Text::Text(const std::string& t) : text(t) { }

void Text::set_pos(const Position& pos) {
    position = pos;
}

void Text::set_color(const std::string& c) {
    color = c;
}

void Text::set_index(std::size_t i) {
    index = i;
}

void Text::set_size(const Size& s) {
    size = s;
}

void Text::set_name(const std::string& n) {
    name = n;
}

Position Text::get_pos() const {
    return position;
}

std::string Text::get_color() const {
    return color;
}

std::size_t Text::get_index() const {
    return index;
}

Size Text::get_size() const {
    return size;
}

void Text::set_content(const std::string& t) {
    text = t;
}

std::string Text::get_content() const {
    return text;
}

std::string Text::get_name() const {
    return name;
}
