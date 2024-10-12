#include "tokenizer.hpp"

std::vector<TokenType> Tokenizer::tokenizer(std::string command_stream) {
    clearVectors();
    std::string token;
    std::istringstream stream(command_stream);
    while (stream >> token) {
        tokens.push_back(token);
        if(std::regex_match(token, shape_option_regex)){
            token_types.push_back(TokenType::SHAPE_OPTION);
        } else if (std::regex_match(token, option_regex)) {
            token_types.push_back(TokenType::OPTION);
        } else if (std::regex_match(token, value_regex)) {
            token_types.push_back(TokenType::VALUE);
        } else if (std::regex_match(token, word_regex)) {
            token_types.push_back(TokenType::WORD);
        } else {
            std::cout << "Invalid token found: " << token << std::endl;
        }
    }
    return token_types;
}

std::vector<std::string> Tokenizer::get_tokens() const{
    return tokens;
}

void Tokenizer::clearVectors(){
    tokens.clear();
    token_types.clear();
}

void Tokenizer::print(){
    for (const auto& it : token_types){
        switch (it)
        {
        case TokenType::OPTION:
            std::cout<<"option\n";
            break;
        case TokenType::SHAPE_OPTION:
            std::cout<<"shape option\n";
            break;
        case TokenType::WORD:
            std::cout<<"word\n";
            break;
        case TokenType::END:
            std::cout<<"end\n";
            break;
        case TokenType::VALUE:
            std::cout<<"value\n";
            break;
        default:
            break;
        }
    }
}