#pragma once

#include <exception>
#include <vector>

#include "tokenizer.hpp"
#include "../Command_Creator/command_list.hpp"

enum class States{
    START_STATE, END_STATE,
    WORD_STATE, OPTION_STATE, SHAPE_OPTION_STATE, VALUE_STATE
};

class SyntaxAnalyzer{
public:
    SyntaxAnalyzer() = default;
    bool analyzer(const std::vector<Token>&);
    //static States current_state;
    
private:
    static States current_state;
    static bool is_single_word;
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