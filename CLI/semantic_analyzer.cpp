#include "semantic_analyzer.hpp"

SemanticAnalyzer::SemanticAnalyzer() { }

bool SemanticAnalyzer::analyze(const std::string& command_name, const std::map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {

    auto command_it = commands.find(command_name);
    if (command_it == commands.end()) {
        std::cerr << "Error";
        return false;
    }

    const CommandList& option = command_it->second;


    for (const auto& [option, expected_type_info] : option.expected_options) {
        auto option_it = options.find(option);
        if (option_it == options.end()) {
            std::cerr << "Error";
            return false;
        }

        const auto& expected_types = expected_type_info.first;
        int expected_count = expected_type_info.second;
        const auto& provided_values = option_it->second;

        if (provided_values.size() != expected_count) {
            std::cerr << "Error";
            return false;
        }

        for (size_t i = 0; i < provided_values.size(); ++i) {
            if (!check_type(provided_values[i], expected_types[i])) {
                std::cerr << "Error";
                return false;
            }
        }
    }

    std::cout << "semantic, command : " << command_name << "'." << std::endl;
    return true;
}

bool SemanticAnalyzer::check_type(const std::variant<int, double, std::string>& value, Token::DataType expected_type) {
    switch (expected_type) {
        case Token::DataType::INT: return std::holds_alternative<int>(value);
        case Token::DataType::DOUBLE: return std::holds_alternative<double>(value);
        case Token::DataType::STRING: return std::holds_alternative<std::string>(value);
        default: return false;
    }
}

std::string SemanticAnalyzer::data_type_to_string(Token::DataType type) {
    switch (type) {
        case Token::DataType::INT: return "int";
        case Token::DataType::DOUBLE: return "double";
        case Token::DataType::STRING: return "string";
        default: return "unknown";
    }
}
