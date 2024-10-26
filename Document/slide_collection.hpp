#pragma once

#include "slide.hpp"

#include <vector>
#include <memory>

class SlideCollection {
public:
    void add_slide(std::shared_ptr<Slide> slide); 
    void remove_slide(std::size_t index);
    std::shared_ptr<Slide> get_slide(std::size_t index) const;
    std::size_t size() const;

private:
    std::vector<std::shared_ptr<Slide>> slides;
};
