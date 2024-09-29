#include "shapes.hpp"

Square::Square(int x, int y, Color c, int s) : Item(x, y, c), size(s) {
    posX = x;
    posY = y;
    color = c;
    type = ItemType::square;
}

int Square::getSize() const{
    return size;
} 

void Square::setSize(const int& s) {
    size = s;
}