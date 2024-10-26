#pragma once

#include "./Parser/tokenizer.hpp"
#include "./Parser/parser.hpp"
#include "./Command_creator/command_factory.hpp"

#include <iostream>

class Controller{
public:
    Controller() { };
    void cli_controller();

private:
};