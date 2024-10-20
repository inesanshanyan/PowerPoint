#pragma once

#include <map>
#include <variant>
#include <vector>
#include <string>
#include <iostream>
#include "tokenizer.hpp"
#include "command_list.hpp"

class SemanticAnalyzer {
public:
    SemanticAnalyzer();
    bool analyze(const std::string& command_name, const std::map<std::string, std::vector<std::variant<int, double, std::string>>>& options);

private:
    CommandList command_list;
    const std::map<std::string, CommandList>& commands = command_list.get_commands();
    
    bool check_type(const std::variant<int, double, std::string>& value, Token::DataType expected_type);
    std::string data_type_to_string(Token::DataType type);
};
