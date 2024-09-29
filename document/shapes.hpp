#pragma once

#include "item.hpp"


class Text : public Item {
public:
    Text(int x, int y, Color c, int s, std::string t);

    int getSize() const;  
    std::string getText() const;

    void setSize(const int&);
    void setText(const std::string&);

private:
    int fontSize;
    std::string text;
};

class Rectangle : public Item{
public:
    Rectangle(int x, int y, Color c, int w, int h);

    std::pair<int, int> getSize() const;  
    void setSize(const int&, const int&);

private:
    int width, height;
};

class Square : public Item {
public:
    Square(int x, int y, Color c, int s);

    int getSize() const;  
    void setSize(const int&);

private: 
    int size;
};


class Circle : public Item {
public:
    Circle(int x, int y, Color c, int r);

    int getSize() const;  
    void setSize(const int&);

private: 
    int radius;
};

