#include "syntax_analyzer.hpp"

States SyntaxAnalyzer::current_state = States::START_STATE;
bool SyntaxAnalyzer::is_single_word = true;

SyntaxErrorException::SyntaxErrorException(const std::string& message)
    : error(message) {}

const char* SyntaxErrorException::what() const noexcept {
    return error.c_str();
}

void SyntaxAnalyzer::print_state(const Token& token) {
    std::cout << "Current Token: ";
    token.print();
    std::cout << "Current State: " << static_cast<int>(current_state) << std::endl;
}

bool SyntaxAnalyzer::check_shape(const std::string& shape) {
    return shape == "ellipse" || shape == "rectangle" || shape == "triangle";
}

bool SyntaxAnalyzer::check_color(const std::string& color) {
    return color == "red" || color == "blue" || color == "green" || color == "yellow" || color == "black" || color == "white";
}

bool SyntaxAnalyzer::analyzer(const std::vector<Token>& token_vec, CommandStruct& command_struct) {
    current_state = States::START_STATE;
    std::string current_option;

    try {
        for (const auto& token : token_vec) {

            switch (current_state) {
                case States::START_STATE:
                    if (token.type == Token::TokenType::WORD) {
                        command_struct.command_name = std::get<std::string>(token.data);
                        current_state = States::WORD_STATE;
                    } else {
                        throw SyntaxErrorException("Expected a command at the start.");
                    }
                    break;

                case States::WORD_STATE:
                    if (token.type == Token::TokenType::OPTION) {
                        current_option = std::get<std::string>(token.data);
                        current_state = States::OPTION_STATE;
                    } else if (token.type == Token::TokenType::END) {
                        return true; 
                    } else {
                        throw SyntaxErrorException("Unexpected token after command name.");
                    }
                    break;

                case States::OPTION_STATE:
                    if (token.type == Token::TokenType::VALUE) {
                        command_struct.options_map[current_option].push_back(token.data);
                        current_state = States::VALUE_STATE;
                    } else if (current_option == "-type" && token.type == Token::TokenType::SHAPE_OPTION) {
                        std::string shape = std::get<std::string>(token.data);
                        if (!check_shape(shape)) {
                            throw SyntaxErrorException("Invalid shape specified.");
                        }
                        command_struct.options_map["-type"].push_back(shape);
                        current_state = States::WORD_STATE;
                    } else if (current_option == "-color" && token.type == Token::TokenType::COLOR_OPTION) {
                        std::string color = std::get<std::string>(token.data);
                        if (!check_color(color)) {
                            throw SyntaxErrorException("Invalid color specified.");
                        }
                        command_struct.options_map["-color"].push_back(color);
                        current_state = States::WORD_STATE;
                    } else if (token.type == Token::TokenType::OPTION) {
                        current_option = std::get<std::string>(token.data);
                    } else if (token.type == Token::TokenType::END) {
                        return true; 
                    } else {
                        throw SyntaxErrorException("Unexpected token after option.");
                    }
                    break;

                case States::VALUE_STATE:
                    if (token.type == Token::TokenType::VALUE) {
                        command_struct.options_map[current_option].push_back(token.data);
                    } else if (token.type == Token::TokenType::OPTION) {
                        current_option = std::get<std::string>(token.data);
                        current_state = States::OPTION_STATE;
                    } else if (token.type == Token::TokenType::END) {
                        return true; 
                    } else {
                        throw SyntaxErrorException("Unexpected token in value state.");
                    }
                    break;

                default:
                    throw SyntaxErrorException("Invalid state.");
            }
        }
    } catch (const SyntaxErrorException& e) {
        std::cerr << "Syntax error: " << e.what() << std::endl;
        return false;
    }

    return false;
}

