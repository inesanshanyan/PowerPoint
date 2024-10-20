#include "parser.hpp"

Parser* Parser::instance = nullptr;

Parser::Parser()  { }

Parser& Parser::getInstance() {
    if(instance == nullptr){
        instance = new Parser();
    }
    return *instance;  
}

void Parser::parser(std::string& command) {
    command_name.clear(); 
    options_map.clear();
    token_vec.clear();

    std::string input;
    std::istringstream stream(command);
    while (stream >> input) {
        Token token;
        token = tokenizer.tokenizer(input, token);
        token_vec.push_back(token);
    }
    
    Token end_token;
    end_token.set_END();
    token_vec.push_back(end_token);

    print_vec();
    if (!syntax.analyzer(token_vec)) {
        return; 
    }
    
    auto token_it = token_vec.begin();
    
    try {
        while (token_it != token_vec.end() && token_it->type != Token::TokenType::END) {
            switch (token_it->type) {
                case Token::TokenType::WORD: {
                    command_name += std::get<std::string>(token_it->data); 
                    ++token_it;
                    break;
                }
                case Token::TokenType::SHAPE_OPTION: {
                    command_name += std::get<std::string>(token_it->data); 
                    ++token_it;
                    break;
                }
                case Token::TokenType::OPTION: {
                    std::string option = std::get<std::string>(token_it->data);
                    ++token_it;

                    std::vector<std::variant<int, double, std::string>> values;
                    while (token_it != token_vec.end() && token_it->type == Token::TokenType::VALUE) {  // to do : for string values
                        values.push_back(token_it->data);
                        ++token_it;
                    }

                    options_map[option] = values;
                    break; 
                }
                case Token::TokenType::END:
                    break;
                default:
                    //++token_it; 
                    break;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "unknown error\n";
    }
    
    if (!semantic.analyze(command_name, options_map)) {
        std::cout << "false\n";
    } else {
        std::cout << "true\n";
    }

    print();
}

void Parser::print() {
    std::cout << "printing options:\n";
    for (const auto& pair : options_map) { 
        std::cout << pair.first << ": ";
        for (const auto& value : pair.second) {
            std::visit([](const auto& val) { std::cout << val << " "; }, value);
        }
        std::cout << std::endl; 
    }
    std::cout << "command name: " << command_name << std::endl;
}


void Parser::print_vec(){
    for(const auto it : token_vec){
        switch (it.type) {
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
    std::cout << std::endl;
}