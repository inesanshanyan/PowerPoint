#pragma once

#include <exception>
#include <vector>
#include <string>
#include <unordered_map>
#include <variant>
#include <iostream>

#include "tokenizer.hpp"
#include "../Command_Creator/command_list.hpp"
#include "command_struct.hpp"

enum class States {
    START_STATE, END_STATE,
    WORD_STATE, OPTION_STATE, VALUE_STATE, SHAPE_STATE, COLOR_STATE
};

class SyntaxAnalyzer {
public:
    SyntaxAnalyzer() = default;
    bool analyzer(const std::vector<Token>& token_vec, CommandStruct& command_struct);

private:
    static States current_state;
    static bool is_single_word;

    static bool check_shape(const std::string& shape);
    static bool check_color(const std::string& color);

    static void print_state(const Token& token);
};

class SyntaxErrorException : public std::exception {
public:
    explicit SyntaxErrorException(const std::string& message);
    virtual const char* what() const noexcept override;

private:
    std::string error;
};
