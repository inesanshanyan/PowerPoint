#pragma once

#include <string>
#include <variant>

struct Position {
    int x = 0;
    int y = 0;
};

using Size = std::variant<int, std::pair<int, int>>;

class Item {
public:
    virtual ~Item() = default;

    virtual void set_pos(const Position&) = 0;
    virtual void set_color(const std::string&) = 0;
    virtual void set_index(std::size_t) = 0;
    virtual void set_size(const Size&) = 0;
    virtual void set_name(const std::string&) = 0;

    virtual Position get_pos() const = 0;
    virtual std::string get_color() const = 0;
    virtual std::size_t get_index() const = 0;
    virtual Size get_size() const = 0;
    virtual std::string get_name() const = 0;

protected:
    Position position;
    std::string color;
    std::size_t index = 0;
    Size size; 
    std::string name; 
};
