#include "shapes.hpp"

Rectangle::Rectangle(int x, int y, Color c, int w, int h)
    : Item(x, y, c), width(w), height(h) {
    posX = x;
    posY = y;
    color = c;
    type = ItemType::rectangle;
}

std::pair<int, int> Rectangle::getSize() const{
    return {width, height};
} 

void Rectangle::setSize(const int& w, const int& h) {
    width = w;
    height = h;
}