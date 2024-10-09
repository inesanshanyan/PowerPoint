#include "CLI/parser.hpp"

int main() {
    std::string command;
    Parser& parser = Parser::getInstance();
    while (std::getline(std::cin, command)) {
        if (command == "exit") {
            break;
        }
        parser.parser(command);
    }
    
    return 0;
}