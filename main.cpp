#include "include/CommandParser.hpp"

int main() {
    CommandParser parser;
    std::string command;
    while (true) {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if (command == "exit") {
            parser.parseCommand(command);
            break;
        }
        parser.parseCommand(command);
    }

    return 0;
}