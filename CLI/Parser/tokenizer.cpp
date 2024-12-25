#include "tokenizer.hpp"

Token::DataType Token::detect_data_type(const std::string& input) {
    if (input.find('.') != std::string::npos) {
        try {
            data = std::stod(input);
            return DataType::DOUBLE;
        } catch (std::invalid_argument&) {
            data = input;
            return DataType::STRING;
        }
    }
    try {
        data = std::stoi(input);
        return DataType::INT;
    } catch (std::invalid_argument&) {
        data = input;
        return DataType::STRING;
    }
}

void Token::set_END() {
    this->type = Token::TokenType::END;
    this->data_type = Token::DataType::STRING;
}

void Token::print() const {
    std::cout << "Token [Type: ";
    switch (type) {
        case TokenType::OPTION: std::cout << "OPTION"; break;
        case TokenType::WORD: std::cout << "WORD"; break;
        case TokenType::VALUE: std::cout << "VALUE"; break;
        case TokenType::END: std::cout << "END"; break;
    }
    std::cout << ", DataType: ";
    switch (data_type) {
        case DataType::INT: std::cout << "INT"; break;
        case DataType::DOUBLE: std::cout << "DOUBLE"; break;
        case DataType::STRING: std::cout << "STRING"; break;
    }
    /*std::cout << ", Data: ";
    std::visit([](auto&& arg) { std::cout << arg; }, data);
    std::cout << "]" << std::endl;*/
}

Tokenizer::Tokenizer()
    : word_regex{"^[a-zA-Z]+"},  
      option_regex{"^-[a-zA-Z]+"},  
      shape_regex{"^ellipse$|^rectangle$|^triangle$"},  
      color_regex{"^red$|^blue$|^green$|^yellow$|^black$|^white$"}, 
      value_regex{"^\\d+(\\.\\d+)?$|^\".*\"$"}  
{ }

std::vector<Token> Tokenizer::tokenizer(const std::string& stream) {
    tokens.clear();
    std::string input;
    std::istringstream stream_stream(stream);

    while (stream_stream >> input) {
        Token token;
        //std::cout << "\ninput in tokenizer " << input;

        try {
            token.data_type = token.detect_data_type(input);

            if (std::regex_match(input, shape_regex)) {
                token.type = Token::TokenType::SHAPE_OPTION;
            } else if (std::regex_match(input, color_regex)) {
                token.type = Token::TokenType::COLOR_OPTION;
            } else if (std::regex_match(input, option_regex)) {
                token.type = Token::TokenType::OPTION;
            } else if (std::regex_match(input, value_regex)) {
                token.type = Token::TokenType::VALUE;
            } else if (std::regex_match(input, word_regex)) {
                token.type = Token::TokenType::WORD;
            } else {
                //std::cerr << "Unrecognized token: " << input << std::endl;
                throw TokenizerErrorException("Unrecognized token: " + input);
            }

            tokens.push_back(token);  
            //std::cout << "\ninput after: " << input;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            throw;
        }
    }

    return tokens;  
}


std::vector<Token> Tokenizer::get_tokens() const {
    return tokens;
}

void Tokenizer::print_tokens() const {
    for (const auto& token : tokens) {
        token.print();
    }
}


TokenizerErrorException::TokenizerErrorException(const std::string& message) 
    : error(message) {}

const char* TokenizerErrorException::what() const noexcept {
    return error.c_str();
}