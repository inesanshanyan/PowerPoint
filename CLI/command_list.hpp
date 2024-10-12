#pragma once

#include <unordered_set>
#include <string>

class CommandList{
public:
    CommandList() = default;  
    std::unordered_set<std::string> command_names = {"addslide", "addshape", "removeslide", "removeshape", "editslide", "editshape"
                                                    "play", "stop", "showslide"};
    std::unordered_set<std::string> option_names = {"-pos", "-size", "-index", "-color"};  
    std::unordered_set<std::string> shape_option_names = {"-rectangle", "-cirlce", "-square"};
           
       
private:
           
};