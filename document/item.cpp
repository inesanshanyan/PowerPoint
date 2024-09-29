#include "item.hpp"

ItemType Item::getType() const{
    return type;
}

std::pair<int, int> Item::getPosition() const{
    return std::make_pair(posX, posY);
}

Color Item::getColor() const{
    return color;
}

std::size_t Item::getIndex() const{
    return index;
}
    
void Item::setPosition(const int& x, const int& y){
    posX = x;
    posY = y;
}

void Item::setColor(const Color& color_){
    color = color_;
}

void Item::setIndex(const std::size_t& index_){
    index = index_;
}