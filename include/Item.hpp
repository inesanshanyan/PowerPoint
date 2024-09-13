#pragma once

#include <string>

namespace doc/*data, document*/{
    class Item {
    public:
        virtual ~Item() = default;

        virtual std::string getType() const = 0;
        virtual int getX() const = 0;
        virtual int getY() const = 0;

        virtual void setPosition(const int&, const int&) = 0;
        virtual void setColor(const std::string&) = 0 ;
        virtual void setSize(const std::size_t&) = 0;

    };
}