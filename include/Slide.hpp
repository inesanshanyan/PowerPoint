#pragma once

#include "item.hpp"

#include <string>
#include <vector>

namespace doc/*data, document*/{
    class Slide{
    public:
        ~Slide() = default;

        void setColor(const std::string&);
        
        void insertItem(const Item&);
        void removeItem(const Item&);


    private:
        std::vector<Item> ItemCollection; 
    };
}