#pragma once

#include <variant>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

#include "tokenizer.hpp" 
#include "../Command_Creator/command_list.hpp"

class SemanticAnalyzer {
public:
    SemanticAnalyzer();
    
    bool analyze(const std::string& command_name, 
                 const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options);

private:
    CommandList command_list;
    std::unordered_map<std::string, Optionlist> commands;

    bool check_type(const std::variant<int, double, std::string>& value, Token::DataType expected_type);
    bool check_color(const std::string& color);
    std::string strip_quotes(const std::string& color);
    std::string data_type_to_string(Token::DataType type);
};


class SemanticErrorException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Semantic Error";
    }
};
