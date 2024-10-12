#include "syntax_analyzer.hpp"

bool SyntaxAnalyzer::syntax_analyzer(std::vector<TokenType> token_types){
    States current_state = States::START_STATE;
    try{
        for (const auto& type : token_types){
            switch(current_state) {
                case States::START_STATE : 
                    if(type == TokenType::WORD) {
                        current_state = States::WORD_STATE;
                    } else throw SyntaxErrorException();
                    break;

                case States::WORD_STATE :
                    if(type == TokenType::OPTION) {
                        current_state = States::OPTION_STATE;
                    } 
                    else if (type == TokenType::SHAPE_OPTION) {
                        current_state = States::SHAPE_OPTION_STATE;
                    } else throw SyntaxErrorException();
                    break;

                case States::OPTION_STATE:
                    if(type == TokenType::VALUE) {
                        current_state = States::VALUE_STATE;
                    } else {
                        throw SyntaxErrorException();
                    }                
                    break;

                case States::SHAPE_OPTION_STATE:
                    if(type == TokenType::OPTION) {
                        current_state = States::OPTION_STATE;
                    } else {
                        throw SyntaxErrorException();
                    }                
                    break;

                case States::VALUE_STATE : 
                    if (type == TokenType::VALUE) {
                        current_state = States::VALUE_STATE;
                    }
                    else if (type == TokenType::OPTION) {
                        current_state = States::OPTION_STATE;
                    }
                    else if (type == TokenType::END) {
                        current_state = States::END_STATE;
                    }
                    else throw SyntaxErrorException();
                    break;
    
                case States::END_STATE :
                    return true;

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
