#pragma once

#include "command.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class CommandParser {
public:
    CommandParser();
    //Command* parseCommand(const std::string&);

private:
    std::string deleteSpaces(const std::string&);
    std::vector<std::string> splitIntoTokens(const std::string&);

};



