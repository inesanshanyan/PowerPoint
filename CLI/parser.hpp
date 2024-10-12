#pragma once 

#include "tokenizer.hpp"
#include "syntax_analyzer.hpp"
#include "semantic_analyzer.hpp"

#include <string>

class Parser{ 
public:
    static Parser& getInstance();
    void parser(std::string command);
    void print();

    Parser(const Parser&) = delete;
    void operator=(const Parser&) = delete;

private:
    Parser() = default;

    std::string command_name;
    std::unordered_map<std::string, std::vector<double>> options_map; 

    Tokenizer tokenizer;
    SyntaxAnalyzer syntax_analyzer;
    //SemanticAnalyzer semantic_analyzer;
};