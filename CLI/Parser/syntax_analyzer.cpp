#include "./syntax_analyzer.hpp"

bool SyntaxAnalyzer::analyzer(const std::vector<Token>& token_vec){
    States current_state = States::START_STATE;
    bool continue_execution = false;
    try{
        for (const auto& token : token_vec){
            switch(current_state) {
                case States::START_STATE : 
                    if(token.type == Token::TokenType::WORD) {
                        current_state = States::WORD_STATE;
                    } 
                    else throw SyntaxErrorException();
                    break;

                case States::WORD_STATE :
                    if(token.type == Token::TokenType::OPTION) {
                        current_state = States::OPTION_STATE;
                    } 
                    else if (token.type == Token::TokenType::SHAPE_OPTION) {
                        current_state = States::SHAPE_OPTION_STATE;
                    } 
                    else if (token.type == Token::TokenType::END) {
                        return true;
                    }
                    else {
                        throw SyntaxErrorException();
                    }
                    break;

                case States::OPTION_STATE:
                    if(token.type == Token::TokenType::VALUE) {
                        current_state = States::VALUE_STATE;
                    } 
                    else {
                        throw SyntaxErrorException();
                    }                
                    break;

                case States::SHAPE_OPTION_STATE:
                    if(token.type == Token::TokenType::OPTION) {
                        current_state = States::OPTION_STATE;
                    }
                    else {
                        throw SyntaxErrorException();
                    }                
                    break;

                case States::VALUE_STATE : 
                    if (token.type == Token::TokenType::VALUE) {
                        current_state = States::VALUE_STATE;
                    }
                    else if (token.type == Token::TokenType::OPTION) {
                        current_state = States::OPTION_STATE;
                    }
                    else if (token.type == Token::TokenType::END) {
                        return true;
                    }
                    else throw SyntaxErrorException();
                    break;

                default :
                    throw UnknownException();
                    break;
                
            }
        }
    }
    catch (const SyntaxErrorException& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    catch (const UnknownException& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return false;
    
}