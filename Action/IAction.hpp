#pragma once

#include "../Document/document.hpp"
#include "../View/view.hpp"

class IAction {
public:
    virtual ~IAction() = default;
    virtual void execute(Document& document) = 0;
    virtual void undo(Document& document) = 0;
    virtual void redo(Document& document) = 0;
};
