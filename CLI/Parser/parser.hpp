#pragma once

#include "tokenizer.hpp"
#include "syntax_analyzer.hpp"
#include "semantic_analyzer.hpp"
#include "../Command_Creator/command_factory.hpp"
#include "command_struct.hpp"

#include <string>
#include <variant>
#include <unordered_map>
#include <vector>
#include <memory>

class Parser {
public:
    Parser(); 
    std::shared_ptr<ICommand> parse(std::string& command);
    void print();


private:
    CommandStruct command_struct;
    std::vector<Token> token_vec;
    void print_vec();

    std::unique_ptr<Tokenizer> tokenizer;
    std::unique_ptr<SyntaxAnalyzer> syntax;
    std::unique_ptr<SemanticAnalyzer> semantic;

    CommandFactory& factory = CommandFactory::get_instance();

    Token* token;
};
