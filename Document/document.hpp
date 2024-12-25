#pragma once

#include "slide.hpp"
#include "./Items/item.hpp"

#include <unordered_map>
#include <memory>
#include <iostream>

class Document {
public:
    void addSlide(); 
    void removeSlide(int slideId);
    std::shared_ptr<Slide> getSlide(int slideId);
    std::shared_ptr<const Slide> getSlide(int slideId) const;

    void addItemToSlide(int slideId, std::shared_ptr<Item> item);
    void removeItemFromSlide(int slideId, int itemId);
    void editItemInSlide(int slideId, int itemId, std::shared_ptr<Item> updatedItem);

    int getSlideIdOfLastAdded() const;

    std::shared_ptr<Slide> getActiveSlide();  
    std::shared_ptr<const Slide> getActiveSlide() const;
    void setActiveSlide(int id);

private:
    std::unordered_map<int, std::shared_ptr<Slide>> slides;
    static int nextSlideId; 
    int activeSlideId; 
};

