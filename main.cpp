#include "CLI/parser.hpp"

int main() {
    std::string command;
    Parser parse;
    while (std::getline(std::cin, command)) {
        if (command == "exit") {
            break;
        }
        parse.parser(command);
    }
    
    return 0;
}