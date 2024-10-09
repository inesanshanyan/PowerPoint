#pragma once

#include <unordered_set>
#include <string>

class CommandList{
public:
    static CommandList& getInstance() {
        static CommandList instance; 
        return instance;       
    }
    CommandList(const CommandList&) = delete;
    void operator=(const CommandList&) = delete;

    std::unordered_set<std::string> command_names = {"addslide", "addshape", "removeslide", "removeshape", "editslide", "editshape"
                                                    "play", "stop", "showslide"};
    std::unordered_set<std::string> option_names = {"-pos", "-size", "-index", "-color", "-rectangle", "-cirlce", "-square"};         
       
private:
    CommandList() = default;         
};