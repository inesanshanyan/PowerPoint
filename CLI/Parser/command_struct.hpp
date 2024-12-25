#pragma once

#include <string>
#include <variant>
#include <unordered_map>
#include <vector>

struct CommandStruct {
    std::string command_name;
    std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>> options_map;
};
