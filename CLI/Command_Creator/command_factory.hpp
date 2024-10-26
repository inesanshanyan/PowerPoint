#pragma once

#include <functional>
#include <memory>
#include <unordered_map>
#include <variant>
#include <vector>
#include <string>
#include <iostream>

#include "../../Commands/command.hpp"

class CommandFactory {
public:
    CommandFactory(const CommandFactory&) = delete;
    CommandFactory& operator=(const CommandFactory&) = delete;

    static CommandFactory& get_instance();

    template<typename CommandType>
    void add_command(const std::string& command_name) {
        std::cout << "Added command: " << command_name << std::endl;
        command_map[command_name] = [](const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
            return std::make_shared<CommandType>(options);
        };
    }


    void set_data(const std::string& command_name, const std::unordered_map<std::string, 
    std::vector<std::variant<int, double, std::string>>>& option_map);

    std::shared_ptr<Command> create_command(); 
    void print_command_map() const;

private:
    CommandFactory() = default;
    std::string command;
    std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>> options;

    std::unordered_map<std::string, std::function<std::shared_ptr<Command>(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>&)>> command_map;
    
};
