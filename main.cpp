#include <iostream>
#include "./document/slide.hpp"
#include "./document/shapes.hpp" 

int main() {
    Slide slide;
    slide.addItem(new Rectangle(10, 20, Color::red, 30, 40));
    slide.addItem(new Square(5, 5, Color::blue, 10));
    slide.addItem(new Circle(15, 15, Color::green, 5));
    std::cout << "Number of items:" << slide.getItemCount() << std::endl;
    slide.removeItem(1);
    std::cout << "Number of items: " << slide.getItemCount() << std::endl;
    slide.setColor(Color::black);
    //std::cout << "Backgournd color" << slide.getColor();

    return 0;
}
