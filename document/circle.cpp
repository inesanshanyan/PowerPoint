#include "shapes.hpp"

Circle::Circle(int x, int y, Color c, int r) : Item(x, y, c), radius(r) {
    posX = x;
    posY = y;
    color = c;
    type = ItemType::circle;
}

int Circle::getSize() const{
    return radius;
} 

void Circle::setSize(const int& r) {
    radius = r;
}
