#pragma once

#include <string>
#include <variant>

struct Position {
    int x = 0;
    int y = 0;
};

struct Color {
    std::string value;
};

using Size = std::variant<int, std::pair<int, int>>;

class Item {
public:
    virtual ~Item() = default;

    virtual void set_pos(const Position&) = 0;
    virtual void set_color(const Color&) = 0;
    virtual void set_index(std::size_t) = 0;
    virtual void set_size(const Size&) = 0;

    virtual Position get_pos() const = 0;
    virtual Color get_color() const = 0;
    virtual std::size_t get_index() const = 0;
    virtual Size get_size() const = 0;

protected:
    Position position;
    Color color;
    std::size_t index = 0;
    Size size;  
};
