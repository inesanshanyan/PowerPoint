#pragma once

#include "../Document/document.hpp"
#include "../Action/IAction.hpp"
#include <memory>
#include <stack>
#include <stdexcept>

class Editor {
public:
    Editor();

    void executeAction(const std::shared_ptr<IAction>& action);
    void undo();
    void redo();

    std::shared_ptr<Document> getDocument() const;

private:
    std::shared_ptr<Document> document; 
    std::stack<std::shared_ptr<IAction>> undoStack;  
    std::stack<std::shared_ptr<IAction>> redoStack;  
};
