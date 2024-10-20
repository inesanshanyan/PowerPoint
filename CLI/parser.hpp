#pragma once 

#include "tokenizer.hpp"
#include "syntax_analyzer.hpp"
#include "semantic_analyzer.hpp"

#include <string>
#include <variant>

class Parser{ 
public:
    static Parser& getInstance();
    void parser(std::string& command);
    void print();

    Parser(const Parser&) = delete;
    void operator=(const Parser&) = delete;

private:
    Parser();
    static Parser* instance;

    std::string command_name;
    std::map<std::string, std::vector<std::variant<int, double, std::string>>> options_map;
    std::vector<Token> token_vec;
    void print_vec();

    Tokenizer tokenizer;
    SyntaxAnalyzer syntax;
    SemanticAnalyzer semantic;

    Token* token;
};