#include "parser.hpp"


Parser& Parser::getInstance() {
    static Parser instance; 
    return instance;       
}

void Parser::parser(std::string command_stream) {
    command_name.clear(); 
    options_map.clear();

    std::vector<TokenType> token_types = tokenizer.tokenizer(command_stream);
    std::vector<std::string> tokens = tokenizer.get_tokens();

    auto token = tokens.begin();
    auto type = token_types.begin();
    try {
        while (type != token_types.end() && *type != TokenType::END) {
            switch (*type) {
                case TokenType::WORD: {
                    command_name += *token;
                    ++token;
                    ++type;
                    break;
                }
                case TokenType::OPTION: {
                    std::vector<double> values;
                    std::string option = *token; 
                    ++token;
                    ++type;
                    while (token != tokens.end() && *type == TokenType::VALUE && type != token_types.end() && *type != TokenType::OPTION ) {
                        try {
                            values.push_back(std::stod(*token));
                            //std::cout << *token;
                        } catch (const std::invalid_argument&) {
                            std::cerr << "invalid value: " << *token << std::endl;
                        }
                        ++token;
                        ++type;
                    }
                    options_map[option] = values;
                    break; 
                }
                case TokenType::END:
                    std::cout << "end";
                    break;
                default:
                    ++type;
                    ++token;
                    break;
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "unknown error" << std::endl;
    }
    
    print();
}


void Parser::print() {
    std::cout<<"printing : \n";
    for (const auto& pair : options_map) { 
        std::cout << pair.first << ": ";
        for (const auto& value : pair.second) { 
            std::cout << value << " "; 
        }
        std::cout << std::endl; 
    }
    std::cout << "command name: " << command_name << std::endl;
}