#include "application.hpp"
#include <iostream>

Application::Application()
    : commandFactory(CommandFactory::get_instance()) { }

void Application::run() {
    std::cout << "Power Point" << std::endl;


    while (view.isOpen()) {
        std::string command;
        std::getline(std::cin, command);

        if (command == "exit") {
            std::cout << "Exiting the Power Point." << std::endl;
            break;
        }

        try {
            auto parsedCommand = parser.parse(command);
            if (parsedCommand) {
                execute_command(parsedCommand, std::cout);
            } else {
                std::cerr << "Error: Invalid command." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        view.render();
    }
}

void Application::execute_command(std::shared_ptr<ICommand>& command, std::ostream& out_stream) {
    if (command) {
        command->execute(editor);
    } else {
        std::cerr << "Error: Command execution failed, invalid state." << std::endl;
    }
}
