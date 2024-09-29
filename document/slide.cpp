#include "slide.hpp"

Slide::Slide(Color c) : bgColor(c) { }

void Slide::addItem(Item* item){
    item->setIndex(ItemCollection.size());
    ItemCollection.push_back(item);
}

void Slide::removeItem(std::size_t index){
    if (index < ItemCollection.size()) {
        delete ItemCollection[index]; //object
        ItemCollection.erase(ItemCollection.begin() + index); // pointer
        updateIndices();
    }
}

Item* Slide::getItem(std::size_t index){
    if (index < ItemCollection.size()) {
        return ItemCollection[index];
    }
    return nullptr; 
}

std::size_t Slide::getItemCount() const{
    return ItemCollection.size();
}

Color Slide::getColor() const{
    return bgColor;
}

std::size_t Slide::getIndex() const{
    return slideIndex;
}

void Slide::setColor(const Color& c){
    bgColor = c;
}

void Slide::setIndex(const std::size_t& i){
    slideIndex = i;
}

void Slide::updateIndices(){  // to do: change to start from a certain index, removeItem
    for (std::size_t i = 0; i < ItemCollection.size(); ++i) {
        ItemCollection[i]->setIndex(i);
    }
}