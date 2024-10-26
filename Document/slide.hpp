#pragma once

#include "item_collection.hpp"  

#include <string>

class Slide {
public:
    Slide(int i, const std::string& c);

    void set_color(const std::string& c);

    void add_item(std::shared_ptr<Item> item); 
    void remove_item(std::size_t index);   
    std::shared_ptr<Item> get_item(std::size_t index) const; 
    std::size_t item_count() const;  

private:
    std::string color;
    ItemCollection items; 
};
