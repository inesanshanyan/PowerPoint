#include "command_factory.hpp"

CommandFactory& CommandFactory::get_instance() {
    static CommandFactory instance;
    return instance;
}

void CommandFactory::set_data(const std::string& command_name, const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& option_map) {
    if (command_map.find(command_name) == command_map.end()) {
        std::cerr << "CommandFactory Error: Command '" << command_name << "' is not registered." << std::endl;
        return;
    }
    command = command_name;
    options = option_map;
    //std::cout << "Set data for command: " << command_name << std::endl;
    for (const auto& [key, values] : option_map) {
        //std::cout << " - Option: " << key << ", Values: ";
        for (const auto& value : values) {
            std::visit([](auto&& arg) { std::cout << arg << " "; }, value);
        }
        std::cout << std::endl;
    }
}

std::shared_ptr<ICommand> CommandFactory::create_command() {
    auto it = command_map.find(command);
    if (it != command_map.end()) {
        //std::cout << "Creating command: " << command << std::endl;
        return it->second(options);
    } else {
        std::cerr << "CommandFactory Error: Unknown command '" << command << "'" << std::endl;
        return nullptr;
    }
}

void CommandFactory::print_command_map() const {
    std::cout << "Registered commands:" << std::endl;
    for (const auto& [command_name, func] : command_map) {
        std::cout << " - Command: " << command_name << std::endl;
    }
}
