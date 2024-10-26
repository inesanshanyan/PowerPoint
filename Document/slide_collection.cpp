#include "slide_collection.hpp"

void SlideCollection::add_slide(std::shared_ptr<Slide> slide) {
    slides.push_back(slide);
}

void SlideCollection::remove_slide(std::size_t index) {
    if (index < slides.size()) {
        slides.erase(slides.begin() + index);
    }
}

std::shared_ptr<Slide> SlideCollection::get_slide(std::size_t index) const {
    if (index < slides.size()) {
        return slides[index];
    }
    return nullptr;
}

std::size_t SlideCollection::size() const {
    return slides.size();
}
