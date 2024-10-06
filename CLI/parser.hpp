#pragma once 

#include "tokenizer.hpp"

#include <string>

class Parser{ 
public:
    void parser(std::string command);
    void print();
private:
    std::string command_name;
    std::unordered_map<std::string, std::vector<double>> options_map; 

};