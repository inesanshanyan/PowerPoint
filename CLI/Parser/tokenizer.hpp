#pragma once

#include <iostream>
#include <vector>
#include <regex>
#include <variant>
#include <sstream>
#include <exception>

struct Token {
public:
    enum class TokenType {
        WORD, OPTION, SHAPE_OPTION, VALUE, COLOR_OPTION, END
    } type;

    enum class DataType {
        INT, DOUBLE, STRING
    } data_type;

    std::variant<int, double, std::string> data;

    DataType detect_data_type(const std::string& input);
    void set_END();
    void print() const;
};

class Tokenizer {
public:
    Tokenizer();
    std::vector<Token> tokenizer(const std::string& stream);
    std::vector<Token> get_tokens() const;
    void print_tokens() const;

private:
    std::regex word_regex;
    std::regex option_regex;
    std::regex shape_regex;
    std::regex color_regex;
    std::regex value_regex;
    std::vector<Token> tokens;
};

class TokenizerErrorException : public std::exception {
public:
    explicit TokenizerErrorException(const std::string& message);
    virtual const char* what() const noexcept override;

private:
    std::string error;
};
