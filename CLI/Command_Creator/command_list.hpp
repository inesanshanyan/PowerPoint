#pragma once

#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>
#include <string>
#include <iostream>

#include "command_factory.hpp"
#include "../Parser/tokenizer.hpp"
#include "include_document.hpp"

struct Optionlist{
    std::unordered_map<std::string, std::pair<std::vector<Token::DataType>, int>> expected_options;
};

struct CommandList {
    std::unordered_map<std::string, Optionlist> get_commands() {
        std::unordered_map<std::string, Optionlist> commands;

        commands["addshape-rectangle"] = {
            {
                {"-size", {{Token::DataType::INT, Token::DataType::INT}, 2}},
                {"-pos", {{Token::DataType::INT, Token::DataType::INT}, 2}},
                {"-color", {{Token::DataType::STRING}, 1}}
            }
        };
        CommandFactory::get_instance().add_command<AddShapeRectangle>("addshape-rectangle");

        commands["addshape-circle"] = {
            {
                {"-size", {{Token::DataType::INT}, 1}},
                {"-pos", {{Token::DataType::INT, Token::DataType::INT}, 2}},
                {"-color", {{Token::DataType::STRING}, 1}}
            }
        };
        CommandFactory::get_instance().add_command<AddShapeCircle>("addshape-circle");

        commands["addshape-square"] = {
            {
                {"-size", {{Token::DataType::INT}, 1}},
                {"-pos", {{Token::DataType::INT, Token::DataType::INT}, 2}},
                {"-color", {{Token::DataType::STRING}, 1}}
            }
        };
        CommandFactory::get_instance().add_command<AddShapeSquare>("addshape-square");


        commands["add-text"] = {
            {
                {"-text", {{Token::DataType::STRING}, 1}},
                {"-size", {{Token::DataType::INT}, 1}},
                {"-pos", {{Token::DataType::INT, Token::DataType::INT}, 2}}
            }
        };
        CommandFactory::get_instance().add_command<AddText>("add-text");

        commands["addslide"] = {
            {
                {"-index", {{Token::DataType::INT}, 1}}
            }
        };
        CommandFactory::get_instance().add_command<AddSlide>("addslide");

        commands["editslide"] = {
            {
                {"-index", {{Token::DataType::INT}, 1}},
                {"-color", {{Token::DataType::STRING}, 1}}
            }
        };
        CommandFactory::get_instance().add_command<EditSlide>("editslide");

        commands["removeshape"] = {
            {
                {"-index", {{Token::DataType::INT}, 1}}
            }
        };
        CommandFactory::get_instance().add_command<RemoveShape>("removeshape");

        commands["removeslide"] = {
            {
                {"-index", {{Token::DataType::INT}, 1}}
            }
        };
        CommandFactory::get_instance().add_command<RemoveSlide>("removeslide");

        commands["play"] = {
            {}
        };
        CommandFactory::get_instance().add_command<Play>("play");

        commands["stop"] = {
            {}
        };
        CommandFactory::get_instance().add_command<Stop>("stop");

        commands["help"] = {
            {}
        };
        CommandFactory::get_instance().add_command<Help>("help");

        commands["showslide"] = {
            {
                {"-index", {{Token::DataType::INT}, 1}}
            }
        };
        CommandFactory::get_instance().add_command<ShowSlide>("showslide");
    
        return commands;
    }

    std::unordered_set<std::string> get_valid_colors(){
        std::unordered_set<std::string> valid_colors = {"red", "blue", "green", "yellow", "black", "white", "orange", "purple", "pink"};
        return valid_colors;
    }

};
