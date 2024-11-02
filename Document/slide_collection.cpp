#include "slide_collection.hpp"

SlideCollection& SlideCollection::get_instance() {
    static SlideCollection instance;
    return instance;
}

void SlideCollection::add_slide(std::shared_ptr<Slide> slide) {
    slides.push_back(slide);
}

void SlideCollection::remove_slide(std::size_t index) {
    if (index >= slides.size()) {
        throw std::out_of_range("Index out of range: Unable to remove slide.");
    }
    slides.erase(slides.begin() + index);
}

void SlideCollection::show(){
    for(const auto s : slides){
        std::cout << "slide " << s->get_index() << ": \n color : " << s->get_color();
        std::cout << "items : ";
        s->show_items();
    }
}

std::shared_ptr<Slide> SlideCollection::get_slide(std::size_t index) const {
    if (index >= slides.size()) {
        throw std::out_of_range("Index out of range: Unable to get slide.");
    }
    return slides.at(index);
}

std::size_t SlideCollection::size() const {
    return slides.size();
}