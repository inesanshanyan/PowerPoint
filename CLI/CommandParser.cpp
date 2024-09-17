#include "../include/CommandParser.hpp"

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

void cli::CommandParser::handleAddSlide() {
    std::cout << "A slide has been added" << std::endl;
}

void cli::CommandParser::handleRemoveSlide() {
    std::cout << "A slide has been removed" << std::endl;
}

void cli::CommandParser::handleAddShape(const std::vector<std::string> &tokens) {
    std::string shapeType = tokens[1];

    int x = std::stoi(tokens[2]);
    int y = std::stoi(tokens[3]);
    std::size_t tokenSize = tokens.size();

    if (shapeType == "rectangle" && tokenSize == 6){
        int width = std::stoi(tokens[4]);
        int height = std::stoi(tokens[5]);
        std::cout << "Added " << shapeType << " at (" << x << ", " << y << "), width = " << width << ", height = " <<height << std::endl;
    } 
    else if(shapeType == "square" && tokenSize == 5){
        int size = std::stoi(tokens[4]);
        std::cout << "Added " << shapeType << " at (" << x << ", " << y << "), size = " << size << std::endl;
    }
    else if (shapeType == "circle" && tokenSize == 5) {
        int size = std::stoi(tokens[4]);
        std::cout << "Added circle at (" << x << ", " << y << "), size = " << size << std::endl;
    } else {
        std::cout << "Unknown shape. Shape options: rectangle, square, circle\n";
    }
}

void cli::CommandParser::handleRemoveShape(const std::vector<std::string> &tokens) {
    std::string shapeType = tokens[1];
    if(shapeType == "rectangle" || shapeType == "square" || shapeType == "circle") {
        std::cout << "Unknown shape. Shape options: rectangle, square, circle\n";
    }
    else{
        std::cout << "Removed " << shapeType << std::endl;
    }
}

void cli::CommandParser::handleGoToSlide(const std::vector<std::string> &tokens) {
    if (tokens.size() < 2) {
        std::cout << "Invalid 'go to slide' command" << std::endl;
        return;
    }
    int slideNumber = std::stoi(tokens[1]);
    std::cout << "Switched to slide " << slideNumber << std::endl;
}

void cli::CommandParser::handleNext() {
    std::cout << "Switched to the next slide" << std::endl;
}


void cli::CommandParser::handlePrev() {
    std::cout << "Switched to the previous slide" << std::endl;
}


void cli::CommandParser::handlePlay() {
    std::cout << "Presentation is now playing" << std::endl;
}

void cli::CommandParser::handlePause() {
    std::cout << "Presentation is now paused" << std::endl;
}


void cli::CommandParser::handleStop() {
    std::cout << "Presentation has been stopped" << std::endl;
}


void cli::CommandParser::handleHelp(){
    std::cout << "Commands to enter: " << std::endl;
    std::cout << "add slide" << std::endl;
    std::cout << "remove slide" << std::endl;
    std::cout << "add rectangle X Y width height" << std::endl;
    std::cout << "add square X Y size" << std::endl;
    std::cout << "add circle X Y size" << std::endl;
    std::cout << "remove rectangle" << std::endl;
    std::cout << "remove square" << std::endl;
    std::cout << "remove circle" << std::endl;
    std::cout << "go to slide_number" << std::endl;
    std::cout << "next" << std::endl;
    std::cout << "prev" << std::endl;
    std::cout << "play" << std::endl;
    std::cout << "pause" << std::endl;
    std::cout << "stop" << std::endl;
    std::cout << "exit" << std::endl;
}

void cli::CommandParser::parseCommand(const std::string &input) {
    std::string trimmed_input = deleteSpaces(input);
    std::vector<std::string> tokens = splitIntoTokens(trimmed_input);
    
    if (tokens.empty()) {
        std::cout << "Invalid command\n";
        return;
    }
    std::size_t commandSize = tokens.size();
    if (tokens[0] == "add") {
        if (commandSize >= 2 && tokens[1] == "slide") {
            handleAddSlide();
        } else if (commandSize >= 2 && (tokens[1] == "rectangle" || tokens[1] == "square" || tokens[1] == "circle")) {
            handleAddShape(tokens);
        } else {
            std::cout << "Unknown 'add' command" << std::endl;
        }
    } else if (tokens[0] == "remove") {
        if (commandSize >= 2 && (tokens[1] == "slide" || tokens[1] == "rectangle" || tokens[1] == "square" || tokens[1] == "circle")) {
            handleRemoveShape(tokens);
        } else {
            std::cout << "Unknown 'remove' command" << std::endl;
        }
    } else if (tokens[0] == "go" && commandSize >= 3 && tokens[1] == "to" && tokens[2] == "slide") {
        handleGoToSlide(tokens);
    } else if (tokens[0] == "next") {
        handleNext();
    } else if (tokens[0] == "prev") {
        handlePrev();
    } else if (tokens[0] == "play") {
        handlePlay();
    } else if (tokens[0] == "pause") {
        handlePause();
    } else if (tokens[0] == "stop") {
        handleStop();
    } else if (tokens[0] == "exit") {
        std::cout << "Exiting" << std::endl;
    } else if(tokens[0] == "help"){
        handleHelp();
    } else {
        std::cout << "Unknown command" << std::endl;
    }
}


