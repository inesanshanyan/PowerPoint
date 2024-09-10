#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class CommandParser {
public:
    CommandParser();
    void parseCommand(const std::string &);

private:
    std::string deleteSpaces(const std::string &);
    std::vector<std::string> splitIntoTokens(const std::string &);

    void handleAddSlide();
    void handleRemoveSlide();

    void handleAddShape(const std::vector<std::string> &);
    void handleRemoveShape(const std::vector<std::string> &);

    void handleGoToSlide(const std::vector<std::string> &);
    void handleNext();
    void handlePrev();
    void handlePlay();
    void handlePause();
    void handleStop();

    void handleHelp();

};


