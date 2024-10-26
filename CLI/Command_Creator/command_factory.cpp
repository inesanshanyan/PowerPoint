#include "command_factory.hpp"


CommandFactory& CommandFactory::get_instance() {
    static CommandFactory instance;
    return instance;
}

void CommandFactory::set_data(const std::string& command_name, const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& option_map) {
    command = command_name;
    options = option_map;
}


std::shared_ptr<Command> CommandFactory::create_command() {
    std::cout << "looking for command: " << command;
    print_command_map();
    auto it = command_map.find(command);
    if (it != command_map.end()) {
        return it->second(options); 
    } else {
        std::cerr << "command factory unknown command: " << command << std::endl;
        return nullptr;
    }
}


void CommandFactory::print_command_map() const {
    std::cout << "added commands:" << std::endl;
    for (const auto& [command_name, func] : command_map) {
        std::cout << " - command: " << command_name 
                      << ", function type: " << typeid(func).name() << std::endl;
    }
}
