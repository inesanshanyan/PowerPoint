#pragma once

#include "../Editor/editor.hpp"
#include "../CLI/Parser/parser.hpp"
#include "../CLI/Command_Creator/command_factory.hpp"
#include "../View/view.hpp"
#include <SFML/Graphics.hpp>

class Application {
public:
    Application();
    void run();

private:
    Editor editor; 
    Parser parser; 
    CommandFactory& commandFactory;
    
    void execute_command(std::shared_ptr<ICommand>& command, std::ostream& out_stream);
    
    View& view = View::getInstance(); 
};
