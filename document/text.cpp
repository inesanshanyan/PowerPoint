#include "shapes.hpp"

Text::Text(int x, int y, Color c, int s, std::string t) : Item(x, y, c), fontSize(s), text(t) {
    posX = x;
    posY = y;
    color = c;
    type = ItemType::text;
}

int Text::getSize() const{
    return fontSize;
} 

std::string Text::getText() const {
    return text;
}

void Text::setSize(const int& s){
    fontSize = s;
}

void Text::setText(const std::string& t) {
    text = t;
}