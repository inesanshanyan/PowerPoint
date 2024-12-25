#pragma once

#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>
#include <string>
#include <iostream>

#include "command_factory.hpp"
#include "../Parser/tokenizer.hpp"
#include "../../Document/document.hpp"
#include "../../Commands/addItemCommand.hpp"
#include "../../Commands/removeItemCommand.hpp"
#include "../../Commands/addSlideCommand.hpp"
#include "../../Commands/removeSlideCommand.hpp"
#include "../../Commands/editItemCommand.hpp"
#include "../../Commands/helpCommand.hpp"
#include "../../Commands/drawSlideCommand.hpp"
#include "../../Commands/undoCommand.hpp"
#include "../../Commands/redoCommand.hpp"
#include "../../Commands/printSlideCommand.hpp"
#include "../../Commands/saveSlideCommand.hpp"
#include "../../Commands/loadSlideCommand.hpp"

struct Optionlist {
    std::unordered_map<std::string, std::pair<std::vector<Token::DataType>, int>> expected_options;
};

struct CommandList {
    std::unordered_map<std::string, Optionlist> get_commands() {
        std::unordered_map<std::string, Optionlist> commands;

        commands["addItem"] = {
            {
                {"-slideID", {{Token::DataType::INT}, 1}}, 
                {"-type", {{Token::DataType::STRING}, 1}},
                {"-pos", {{Token::DataType::DOUBLE, Token::DataType::DOUBLE}, 2}},  
                {"-size", {{Token::DataType::DOUBLE, Token::DataType::DOUBLE}, 2}}, 
                {"-color", {{Token::DataType::STRING}, 1}} 
            }
        };
        CommandFactory::get_instance().add_command<AddItemCommand>("addItem");

        
        commands["removeItem"] = {
            {
                {"-slideID", {{Token::DataType::INT}, 1}},
                {"-id", {{Token::DataType::INT}, 1}}     
            }
        };
        CommandFactory::get_instance().add_command<RemoveItemCommand>("removeItem");

        
        commands["editItem"] = {
            {
                {"-slideID", {{Token::DataType::INT}, 1}},
                {"-id", {{Token::DataType::INT}, 1}},     
                {"-pos", {{Token::DataType::DOUBLE, Token::DataType::DOUBLE}, 2}},  
                {"-size", {{Token::DataType::DOUBLE, Token::DataType::DOUBLE}, 2}}, 
                {"-color", {{Token::DataType::STRING}, 1}} 
            }
        };
        CommandFactory::get_instance().add_command<EditItemCommand>("editItem");

        
        commands["addSlide"] = {};
        CommandFactory::get_instance().add_command<AddSlideCommand>("addSlide");

        
        commands["removeSlide"] = {
            {
                {"-id", {{Token::DataType::INT}, 1}}
            }
        };
        CommandFactory::get_instance().add_command<RemoveSlideCommand>("removeSlide");


        commands["drawSlide"] = {
            {
                {"-id", {{Token::DataType::INT}, 1}} 
            }
        };
        CommandFactory::get_instance().add_command<DrawSlideCommand>("drawSlide");

        commands["printSlide"] = {
            {
                {"-id", {{Token::DataType::INT}, 1}} 
            }
        };
        CommandFactory::get_instance().add_command<PrintSlideCommand>("printSlide");

        
        commands["help"] = {};
        CommandFactory::get_instance().add_command<HelpCommand>("help");

        commands["undo"] = {};
        CommandFactory::get_instance().add_command<UndoCommand>("undo");

        commands["redo"] = {};
        CommandFactory::get_instance().add_command<RedoCommand>("redo");


        commands["saveSlide"] = {
            {
                {"-id", {{Token::DataType::INT}, 1}} 
            }
        };
        CommandFactory::get_instance().add_command<SaveSlideCommand>("saveSlide");


        commands["loadSlide"] = {};
        CommandFactory::get_instance().add_command<LoadSlideCommand>("loadSlide");

        return commands;
    }

    std::unordered_set<std::string> get_valid_colors() {
        std::unordered_set<std::string> valid_colors = {"red", "blue", "green", "yellow", "black", "white"};
        //std::cout << "Initialized valid colors" << std::endl;
        return valid_colors;
    }
};
