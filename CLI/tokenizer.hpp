#pragma once

#include <iostream>
#include <vector>
#include <regex>

enum class TokenType{
    WORD, OPTION, VALUE, END
};

class Tokenizer{
public:
    std::vector<TokenType> tokenizer(std::string command_stream);
    std::vector<std::string> get_tokens() const;
    void clearVectors();
private:
    std::regex word_regex{"[a-zA-Z]+"};
    std::regex option_regex{"-[a-zA-Z]+"};
    std::regex value_regex{"-?\\d+(\\.\\d+)?"};
    std::regex end_regex{"\\n"};

    std::vector<std::string> tokens;
    std::vector<TokenType> token_types;
};