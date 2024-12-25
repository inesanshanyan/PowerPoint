#pragma once

class Geometry {
public:
    Geometry(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {}

    int getX() const { 
        return x; 
    }

    int getY() const {
        return y; 
    }

    int getWidth() const { 
        return width; 
    }
    
    int getHeight() const { 
        return height; 
    }


private:
    int x, y, width, height;
};
