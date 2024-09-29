#pragma once

#include <string>
#include <utility>

enum class ItemType {
    text, rectangle, circle, square
};

enum class Color { // ?? overload << 
    white, black, red, green, blue
};

class Item {
public:
    Item(int x , int y , Color c) : posX(x), posY(y), color(c) { }
    virtual ~Item() = default;

    virtual ItemType getType() const;
    virtual std::pair<int, int> getPosition() const;
    virtual Color getColor() const;
    virtual std::size_t getIndex() const;
    
    virtual void setPosition(const int&, const int&);
    virtual void setColor(const Color&);
    virtual void setIndex(const std::size_t&);


protected:
    int posX = 0, posY = 0;
    Color color = Color::white;
    std::size_t index = 0;
    ItemType type = ItemType::rectangle;

};