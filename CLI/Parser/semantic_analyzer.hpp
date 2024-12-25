#pragma once

#include <variant>
#include <vector>
#include <string>
#include <unordered_map>
#include <exception>

#include "tokenizer.hpp"
#include "../Command_Creator/command_list.hpp"
#include "command_struct.hpp"


class SemanticAnalyzer {
public:
    SemanticAnalyzer();
    bool analyze(const CommandStruct& command_struct);

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
    explicit SemanticErrorException(const std::string& message);
    virtual const char* what() const noexcept override;

private:
    std::string error;
};
