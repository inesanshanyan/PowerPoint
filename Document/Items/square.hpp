#pragma once

#include "item.hpp"

class Square : public Item {
public:
    Square(int s);

    void set_pos(const Position& pos) override;
    void set_color(const std::string& c) override;
    void set_index(std::size_t i) override;
    void set_size(const Size& s) override;
    void set_name(const std::string&) override;

    Position get_pos() const override;
    std::string get_color() const override;
    std::size_t get_index() const override;
    Size get_size() const override;
    std::string get_name() const override;
};
