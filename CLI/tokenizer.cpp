#include "tokenizer.hpp"

Token Tokenizer::tokenizer(std::string input, Token& token) {
    token.data_type = token.detect_data_type(input);
    if (std::regex_match(input, shape_option_regex)) {
        token.type = Token::TokenType::SHAPE_OPTION;
    } 
    else if (std::regex_match(input, value_regex)) {  
        token.type = Token::TokenType::VALUE;
    } 
    else if (std::regex_match(input, option_regex)) {
        token.type = Token::TokenType::OPTION;
    } 
    else if (std::regex_match(input, word_regex)) {
        token.type = Token::TokenType::WORD;
    } 
    else {
        std::cout << "Invalid token found: " << input << std::endl;
    }

    return token;
}


void Tokenizer::print(const Token& token){
    switch (token.type) {
    case Token::TokenType::OPTION:
        std::cout<<"option\n";
        break;
    case Token::TokenType::SHAPE_OPTION:
        std::cout<<"shape option\n";
        break;
    case Token::TokenType::WORD:
        std::cout<<"word\n";
        break;
    case Token::TokenType::END:
        std::cout<<"end\n";
        break;
    case Token::TokenType::VALUE:
        std::cout<<"value\n";
        break;
    default:
        break;
    }
}

/*void Tokenizer::set_END(Token& end) const {
    Token end;
    end.type = Token::TokenType::WORD;
    end.data_type = Token::DataType::STRING;
}*/