#include "semantic_analyzer.hpp"

SemanticAnalyzer::SemanticAnalyzer() {
    commands = command_list.get_commands();
}

bool SemanticAnalyzer::analyze(const std::string& command_name, const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
    try{
        if (commands.find(command_name) == commands.end()) {
            throw SemanticErrorException();
            return false;
        }

        const Optionlist& expected_optionlist = commands[command_name];

        for (const auto& option : options) {
            const std::string& option_name = option.first;

            if (expected_optionlist.expected_options.find(option_name) == expected_optionlist.expected_options.end()) {
                throw SemanticErrorException();
                return false;
            }

            const auto& expected = expected_optionlist.expected_options.at(option_name);
            const std::vector<Token::DataType>& expected_types = expected.first;
            int expected_arg_count = expected.second;

            const std::vector<std::variant<int, double, std::string>>& provided_args = option.second;

            if (provided_args.size() != expected_arg_count) {
                throw SemanticErrorException();
                return false;
            }

            for (size_t i = 0; i < provided_args.size(); ++i) {
                if (option_name == "-color") {
                const auto& color = std::get<std::string>(provided_args[i]);
                if (!check_color(color)) {
                    std::cout << "wrong color";
                    throw SemanticErrorException();
                    return false;
                }
            } else if (!check_type(provided_args[i], expected_types[i])) {
                throw SemanticErrorException();
                return false;
            }
            }
        }
    }
    catch (const SemanticErrorException& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    catch (...) {
        std::cerr << "Unknown error" << std::endl;
        return false;
    }
    return true;
}

bool SemanticAnalyzer::check_type(const std::variant<int, double, std::string>& value, Token::DataType expected_type) {
    switch (expected_type) {
        case Token::DataType::INT:
            return std::holds_alternative<int>(value);
        case Token::DataType::DOUBLE:
            return std::holds_alternative<double>(value);
        case Token::DataType::STRING:
            return std::holds_alternative<std::string>(value);
        default:
            return false;
    }
}

bool SemanticAnalyzer::check_color(const std::string& c) {
    std::string color = strip_quotes(c);  
    auto valid_colors = command_list.get_valid_colors(); 
    bool check = valid_colors.find(color) != valid_colors.end();
    //std::cout << "\ncolor " << color << " " << check << "\n";
    return check;
}

std::string SemanticAnalyzer::strip_quotes(const std::string& c) {
    if (c.size() >= 2 && c.front() == '"' && c.back() == '"') {
        return c.substr(1, c.size() - 2); 
    }
    return c;
}

std::string SemanticAnalyzer::data_type_to_string(Token::DataType type) {
    switch (type) {
        case Token::DataType::INT:
            return "INT";
        case Token::DataType::DOUBLE:
            return "DOUBLE";
        case Token::DataType::STRING:
            return "STRING";
        default:
            return "UNKNOWN";
    }
}
