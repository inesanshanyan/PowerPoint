#pragma once

#include "item_collection.hpp"  

#include <string>

class Slide {
public:
    Slide(int i, const std::string& c);

    void set_color(const std::string& c);
    std::string get_color() const;
    void set_index(const int& c);
    int get_index() const;

    void add_item(std::shared_ptr<Item> item); 
    void remove_item(std::size_t index);
    void show_items();   
    std::shared_ptr<Item> get_item(std::size_t index) const; 
    std::size_t item_count() const;  

private:
    int index;
    std::string color;
    ItemCollection items; 
};
