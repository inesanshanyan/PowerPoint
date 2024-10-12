#pragma once

#include <exception>
#include <vector>

#include "tokenizer.hpp"
#include "command_list.hpp"

enum class States{
    START_STATE, END_STATE,
    WORD_STATE, OPTION_STATE, SHAPE_OPTION_STATE, VALUE_STATE
};

class SyntaxAnalyzer{
public:
    SyntaxAnalyzer() = default;
    bool syntax_analyzer(std::vector<TokenType>);

};

class SyntaxErrorException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Syntax Error";
    }
};

class UnknownException : public std::exception {
public:
    const char* what() const noexcept override {
        return "An unknown error occurred.";
    }
};