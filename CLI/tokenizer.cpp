#include "tokenizer.hpp"

std::vector<TokenType> Tokenizer::tokenizer(std::string command_stream) {
    clearVectors();
    std::string token;
    std::istringstream stream(command_stream);
    while (stream >> token) {
        tokens.push_back(token);
        if (std::regex_match(token, option_regex)) {
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