#pragma once

#include "slide.hpp"

#include <vector>
#include <memory>
#include <stdexcept>
#include <iostream>

class SlideCollection {
public:
    static SlideCollection& get_instance();
    SlideCollection(const SlideCollection&) = delete;
    SlideCollection& operator=(const SlideCollection&) = delete;

    void add_slide(std::shared_ptr<Slide> slide); 
    void remove_slide(std::size_t index);
    void show();
    std::shared_ptr<Slide> get_slide(std::size_t index) const;
    std::size_t size() const;

private:
    SlideCollection() = default;
    std::vector<std::shared_ptr<Slide>> slides;
};
