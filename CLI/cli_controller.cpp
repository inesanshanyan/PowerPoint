#include "cli_controller.hpp"


void Controller::cli_controller(){
    while(true){
        std::string command;
        while(true){
            getline(std::cin, command);
            Parser::getInstance(CommandFactory::get_instance()).parser(command);
            std::shared_ptr<Command> cmd = CommandFactory::get_instance().create_command();  
            cmd->execute();          
        }
        
    }
    
}

