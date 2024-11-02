#pragma once

#include "command.hpp"

class Help : public Command {
public:
    Help(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {   }
    void execute() override {
        //std::cout << "Executing Help command." << std::endl;
        std::cout << "Print a command (the order of options (pos, size, color) does not matter)\n\n";
        std::cout << "addshape -rectangle -size num num -pos num num -color \"string\" -slideindex num" << std::endl;
        std::cout << "addshape -circle -size number -pos num num -color \"string\" -slideindex num " << std::endl;
        std::cout << "addshape -square -size number -pos num num -color \"string\" -slideindex num " << std::endl;
        std::cout << "addshape -text \"string\" -size num -pos num num" << std::endl;
        std::cout << "addslide -index num" << std::endl;
        std::cout << "editslide -index num -color str" << std::endl;
        std::cout << "removeshape -index num" << std::endl;
        std::cout << "removeslide -index num" << std::endl;
        std::cout << "play" << std::endl;
        std::cout << "stop" << std::endl;
        std::cout << "help" << std::endl;
        std::cout << "showslide -index" << std::endl;
    }
};