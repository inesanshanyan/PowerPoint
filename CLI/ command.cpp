#include "../include/command.hpp"

namespace cli {

    //slide commands
    void AddSlideCommand::execute() {
        std::cout << "slide has been added" << std::endl;
    }

    void RemoveSlideCommand::execute() {
        std::cout << "slide at index " << index << " has been removed" << std::endl;
    }

    //shape commands
    void AddRectangleCommand::execute() {
        std::cout << "added rectangle with coord (" << x << ", " << y << ") and size " << width << "x" << height << std::endl;
    }

    void AddSquareCommand::execute() {
        std::cout << "added square with coord (" << x << ", " << y << ") and size " << size << "x" << size << std::endl;
    }

    void AddCircleCommand::execute() {
        std::cout << "added circle with center (" << x << ", " << y << ") and radius " << size << std::endl;
    }

    void RemoveRectangleCommand::execute() {
        std::cout << "rectangle at index " << index << " has been removed" << std::endl;
    }

    void RemoveSquareCommand::execute() {
        std::cout << "square at index " << index << " has been removed" << std::endl;
    }

    void RemoveCircleCommand::execute() {
        std::cout << "circle at index " << index << " has been removed" << std::endl;
    }

    //text commands
    void AddTextCommand::execute() {
        std::cout << "added text at (" << x << ", " << y << "): \"" << text << "\"" << std::endl;
    }

    //control commands
    void PlayCommand::execute() {
        std::cout << "Playing presentation starting from slide " << startIndex << std::endl;
    }

    void StopCommand::execute() {
        std::cout << "stopping presentation" << std::endl;
    }

    void NextCommand::execute() {
        std::cout << "moving to the next slide" << std::endl;
    }

    void PrevCommand::execute() {
        std::cout << "moving to the previous slide" << std::endl;
    }

    void GoToSlideCommand::execute() {
        std::cout << "going to slide at index " << index << std::endl;
    }

    void PauseCommand::execute() {
        std::cout << "pausing presentation" << std::endl;
    }
    
    void HelpCommand::execute() {
         std::cout << "Commands to enter: " << std::endl;
        std::cout << "add slide" << std::endl;
        std::cout << "remove slide" << std::endl;
        std::cout << "add rectangle X Y width height" << std::endl;
        std::cout << "add square X Y size" << std::endl;
        std::cout << "add circle X Y size" << std::endl;
        std::cout << "add text X Y text" << std::endl;
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

    void ExitCommand::execute() {
        std::cout << "exiting" << std::endl;
    }
}
