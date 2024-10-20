#include "cli_controller.hpp"


void Controller::cli_controller(){
    /*if(!token_vec.empty()){
        token_vec.clear();
    }*/
    while(true){
        std::string command;

        while(true){
            getline(std::cin, command);
            Parser::getInstance().parser(command);
        }
        
    }
    
}

