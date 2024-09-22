#include "../include/commandParser.hpp"

cli::CommandParser::CommandParser() { }

std::string cli::CommandParser::deleteSpaces(const std::string &str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');

    return str.substr(first, (last - first + 1));
}

std::vector<std::string> cli::CommandParser::splitIntoTokens(const std::string &str) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string word;
    while (ss >> word) {
        tokens.push_back(word);
    }
    return tokens;
}

cli::Command* cli::CommandParser::parseCommand(const std::string &input) { 
    std::string trimmed_input = deleteSpaces(input);  
    std::vector<std::string> tokens = splitIntoTokens(trimmed_input); 
    
    if (tokens.empty()) {
        std::cout << "invalid command\n";
        return nullptr;
    }

    std::size_t commandSize = tokens.size();
    
    //add commands
    if (tokens[0] == "add") {
        if (commandSize >= 2 && tokens[1] == "slide") {
            return new AddSlideCommand();
        } else if (commandSize >= 2 && tokens[1] == "rectangle") {
            if (commandSize == 6) {
                int x = std::stoi(tokens[2]);
                int y = std::stoi(tokens[3]);
                int width = std::stoi(tokens[4]);
                int height = std::stoi(tokens[5]);
                return new AddRectangleCommand(x, y, width, height);
            } else {
                std::cout << "invalid format for 'add rectangle', usage: add rectangle x y width height\n";
            }
        } else if (commandSize >= 2 && tokens[1] == "square") {
            if (commandSize == 5) {
                int x = std::stoi(tokens[2]);
                int y = std::stoi(tokens[3]);
                int size = std::stoi(tokens[4]);
                return new AddSquareCommand(x, y, size); 
            } else {
                std::cout << "invalid format for 'add square', usage: add square x y size\n";
            }
        } else if (commandSize >= 2 && tokens[1] == "circle") {
            if (commandSize == 5) {
                int x = std::stoi(tokens[2]);
                int y = std::stoi(tokens[3]);
                int size = std::stoi(tokens[4]);
                return new AddCircleCommand(x, y, size);
            } else {
                std::cout << "invalid format for 'add circle', usage: add circle x y size\n";
            }
        } else {
            std::cout << "unknown 'add' command" << std::endl;
        }
    }

    //remove commands
    else if (tokens[0] == "remove") {
        if (commandSize >= 2 && tokens[1] == "slide") {
            if (commandSize == 3) {
                std::size_t index = std::stoul(tokens[2]);
                return new RemoveSlideCommand(index);
            } else {
                std::cout << "invalid format for 'remove slide', usage: remove slide index\n";
            }
        } else if (commandSize >= 2 && tokens[1] == "rectangle") {
            if (commandSize == 3) {
                std::size_t index = std::stoul(tokens[2]);
                return new RemoveRectangleCommand(index);
            } else {
                std::cout << "invalid format for 'remove rectangle', usage: remove rectangle index\n";
            }
        } else {
            std::cout << "unknown 'remove' command" << std::endl;
        }
    }

    //control commands  
    else if (tokens[0] == "next") {
        return new NextCommand();
    } else if (tokens[0] == "prev") {
        return new PrevCommand();
    }
    else if (tokens[0] == "go" && commandSize >= 3 && tokens[1] == "to" && tokens[2] == "slide") {
        if (commandSize == 4) {
            std::size_t index = std::stoul(tokens[3]);
            return new GoToSlideCommand(index);  // Assuming you have GoToSlideCommand class
        } else {
            std::cout << "invalid format for 'go to slide', usage: go to slide index\n";
        }
    }

    else if (tokens[0] == "play") {
        return new PlayCommand(0);  
    } else if (tokens[0] == "pause") {
        return new PauseCommand();
    } else if (tokens[0] == "stop") {
        return new StopCommand();
    }
    else if (tokens[0] == "exit") {
        return new ExitCommand();
    }
    else if (tokens[0] == "help") {
        return new HelpCommand(); 
    }
    else {
        std::cout << "unknown command" << std::endl;
    }

    return nullptr;
}



