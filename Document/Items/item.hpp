#pragma once

#include "geometry.hpp"
#include "attribute.hpp"
#include "render_info.hpp"
#include <iostream>
#include <memory>

class Item {
public:
    Item(int id, Shape shape, const Geometry& geometry, const Attribute& attribute);

    RenderInfo getRenderInfo() const;
    void setRenderInfo(const RenderInfo& renderInfo);

    int getID() const;
    void setID(const int& id);

    Shape getShape() const;
    void setShape(Shape new_shape);

    const Geometry& getGeometry() const;
    void setGeometry(const Geometry& new_geometry);

    const Attribute& getAttribute() const;
    void setAttribute(const Attribute& new_attribute);

private:
    int id;
    Shape shape; 
    Geometry geometry;
    Attribute attribute;
};