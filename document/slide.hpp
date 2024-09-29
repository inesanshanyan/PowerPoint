#pragma once

#include "item.hpp"

#include <vector>

class Slide {
public:
    Slide() = default;
    Slide(Color);

    void addItem(Item*);
    void removeItem(std::size_t);

    Item* getItem(std::size_t);
    std::size_t getItemCount() const;

    Color getColor() const;
    std::size_t getIndex() const;

    void setColor(const Color&);
    void setIndex(const std::size_t&);

private:
    std::vector<Item*> ItemCollection; 
    void updateIndices();

    Color bgColor = Color::white;
    std::size_t slideIndex = 0;

};
