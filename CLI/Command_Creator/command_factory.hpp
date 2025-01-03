#pragma once

#include <functional>
#include <memory>
#include <unordered_map>
#include <variant>
#include <vector>
#include <string>
#include <iostream>

#include "../../Commands/ICommand.hpp"

class CommandFactory {
public:
    CommandFactory(const CommandFactory&) = delete;
    CommandFactory& operator=(const CommandFactory&) = delete;

    static CommandFactory& get_instance();

    template<typename CommandType>
    void add_command(const std::string& command_name) {
        command_map[command_name] = [](const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) -> std::shared_ptr<ICommand> {
            return std::make_shared<CommandType>(options); 
        };
    }

    void set_data(const std::string& command_name, const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& option_map);

    std::shared_ptr<ICommand> create_command();   

    void print_command_map() const;

private:
    CommandFactory() = default;
    std::string command;  
    std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>> options; 

    std::unordered_map<std::string, std::function<std::shared_ptr<ICommand>(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>&)>> command_map;
};
