#pragma once

#include "attribute.hpp"
#include <tuple>

enum class Shape {
    RECTANGLE,
    TRIANGLE,
    ELLIPSE
};

struct RenderInfo {
    Shape shape;
    float x, y; 
    float width, height;  
    Attribute attribute;

    RenderInfo(Shape shape, float x, float y, float width, float height, const Attribute& color)
        : shape(shape), x(x), y(y), width(width), height(height), attribute(color) {}
};
