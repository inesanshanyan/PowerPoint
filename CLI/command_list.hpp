#pragma once

#include <map>
#include <variant>
#include <vector>
#include <string>
#include <iostream>

struct CommandList {
    std::map<std::string, std::pair<std::vector<Token::DataType>, int>> expected_options;


    std::map<std::string, CommandList> get_commands() {
        std::map<std::string, CommandList> commands;

        commands["addshape-rectangle"] = {
            {
                {"-size", {{Token::DataType::INT, Token::DataType::INT}, 2}},
                {"-pos", {{Token::DataType::INT, Token::DataType::INT}, 2}},
                {"-color", {{Token::DataType::STRING}, 1}}
            }
        };

        commands["addshape-circle"] = {
            {
                {"-size", {{Token::DataType::INT}, 1}},
                {"-pos", {{Token::DataType::INT, Token::DataType::INT}, 2}},
                {"-color", {{Token::DataType::STRING}, 1}}
            }
        };

        commands["addshape-square"] = {
            {
                {"-size", {{Token::DataType::INT}, 1}},
                {"-pos", {{Token::DataType::INT, Token::DataType::INT}, 2}},
                {"-color", {{Token::DataType::STRING}, 1}}
            }
        };

    //to do : add more commands
        return commands;
    }

};
