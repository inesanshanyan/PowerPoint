#pragma once

#include <string>

#include "../../Serialize/json.hpp"

class Attribute {
public:
    Attribute(const std::string& color)
        : color(color)  {}

    const std::string& getColor() const { 
        return color; 
    }

    nlohmann::json toJson() const {
        return nlohmann::json{{"color", color}};
    }

    static Attribute fromJson(const nlohmann::json& json) {
        return Attribute(json.at("color").get<std::string>());
    }


private:
    std::string color;
};

