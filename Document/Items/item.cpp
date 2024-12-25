#include "item.hpp"

Item::Item(int id, Shape shape, const Geometry& geometry, const Attribute& attribute)
    : id(id), shape(shape), geometry(geometry), attribute(attribute) {}

int Item::getID() const {
    return id;
}

void Item::setID(const int& ID) {
    id = ID;
}

Shape Item::getShape() const {
    return shape;
}

void Item::setShape(Shape new_shape) {
    shape = new_shape;
}

const Geometry& Item::getGeometry() const {
    return geometry;
}

void Item::setGeometry(const Geometry& new_geometry) {
    geometry = new_geometry;
}

const Attribute& Item::getAttribute() const {
    return attribute;
}

void Item::setAttribute(const Attribute& new_attribute) {
    attribute = new_attribute;
}

RenderInfo Item::getRenderInfo() const {
    return RenderInfo(
        shape, 
        geometry.getX(), geometry.getY(),
        geometry.getWidth(), geometry.getHeight(),
        attribute
    );
}

void Item::setRenderInfo(const RenderInfo& renderInfo) {
    geometry = Geometry(renderInfo.x, renderInfo.y, renderInfo.width, renderInfo.height);
    attribute = renderInfo.attribute;
    shape = renderInfo.shape;
}