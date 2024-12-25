#include "parser.hpp"
#include <iostream>


Parser::Parser() 
    : tokenizer(std::make_unique<Tokenizer>()),
      syntax(std::make_unique<SyntaxAnalyzer>()),
      semantic(std::make_unique<SemanticAnalyzer>()) { }

std::shared_ptr<ICommand> Parser::parse(std::string& command) {
    command_struct.command_name.clear();
    command_struct.options_map.clear();
    token_vec.clear();

    Tokenizer tokenizer;
    token_vec = tokenizer.tokenizer(command);
    Token end_token;
    end_token.set_END();
    token_vec.push_back(end_token);
    //print_vec();

    if (!syntax->analyzer(token_vec, command_struct)) {
        std::cerr << "Syntax analysis failed.\n";
        return nullptr;
    }

    if (!semantic->analyze(command_struct)) {
        std::cerr << "Semantic analysis failed.\n";
        return nullptr;
    }

    factory.set_data(command_struct.command_name, command_struct.options_map);
    return factory.create_command(); 
}

void Parser::print() {
    std::cout << "Parsed Command:" << std::endl;
    std::cout << "Command Name: " << command_struct.command_name << std::endl;


    std::cout << "Options:" << std::endl;
    for (const auto& pair : command_struct.options_map) {
        std::cout << "  " << pair.first << ": ";
        for (const auto& value : pair.second) {
            std::visit([](const auto& val) { std::cout << val << " "; }, value);
        }
        std::cout << std::endl;
    }
}

void Parser::print_vec() {
    for (const auto& it : token_vec) {
        switch (it.type) {
        case Token::TokenType::OPTION:
            std::cout << "option\n";
            break;
        case Token::TokenType::WORD:
            std::cout << "word\n";
            break;
        case Token::TokenType::END:
            std::cout << "end\n";
            break;
        case Token::TokenType::VALUE:
            std::cout << "value\n";
            break;
        case Token::TokenType::SHAPE_OPTION:
            std::cout << "shape option";
            break;
        case Token::TokenType::COLOR_OPTION:
            std::cout << "color option";
            break;
        default:
            break;
        }
    }
    std::cout << std::endl;
}
