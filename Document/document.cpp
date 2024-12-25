#include "document.hpp"

int Document::nextSlideId = 1;

void Document::addSlide() {
    int slideId = nextSlideId++;
    slides[slideId] = std::make_shared<Slide>();
    std::cout << "Added Slide with ID: " << slideId << "\n";
}


void Document::removeSlide(int slideId) {
    slides.erase(slideId);
}

std::shared_ptr<Slide> Document::getSlide(int slideId) {
    auto it = slides.find(slideId);
    if (it != slides.end()) {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<const Slide> Document::getSlide(int slideId) const {
    auto it = slides.find(slideId);
    if (it != slides.end()) {
        return it->second;
    }
    return nullptr;
}

void Document::addItemToSlide(int slideId, std::shared_ptr<Item> item) {
    auto slide = getSlide(slideId);
    if (slide) {
        Shape type = item->getShape(); 
        Geometry geometry = item->getGeometry();  
        Attribute attribute = item->getAttribute(); 

        slide->addItem(type, geometry, attribute);
    } else {
        std::cout << "Slide with ID " << slideId << " not found.\n";
    }
}

void Document::removeItemFromSlide(int slideId, int itemId) {
    auto slide = getSlide(slideId);
    if (slide) {
        //std::cout << "\n item from slide removed " << slideId << " " << itemId;
        slide->removeItem(itemId);
    } else {
        std::cout << "Slide with ID " << slideId << " not found.\n";
    }
}

void Document::editItemInSlide(int slideId, int itemId, std::shared_ptr<Item> updatedItem) {
    auto slide = getSlide(slideId);
    if (slide) {
        slide->editItem(itemId, updatedItem);
    } else {
        std::cout << "Slide with ID " << slideId << " not found.\n";
    }
}



int Document::getSlideIdOfLastAdded() const { 
    return nextSlideId - 1; 
}


std::shared_ptr<Slide> Document::getActiveSlide() {
    return getSlide(activeSlideId);  
}

std::shared_ptr<const Slide> Document::getActiveSlide() const {
    return getSlide(activeSlideId); 
}

void Document::setActiveSlide(int id) {
    if (slides.find(id) == slides.end()) {
        throw std::runtime_error("Slide with this ID does not exist");
    }
    activeSlideId = id;
}