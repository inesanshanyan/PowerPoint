#include "editor.hpp"
#include <iostream>

Editor::Editor() : document(std::make_shared<Document>()) {}

void Editor::executeAction(const std::shared_ptr<IAction>& action) {
    if (!action) {
        throw std::runtime_error("Invalid action");
    }

    action->execute(*document);
    undoStack.push(action);

    while (!redoStack.empty()) {
        redoStack.pop();
    }
}

void Editor::undo() {
    if (undoStack.empty()) {
        std::cout << "No actions to undo.\n";
        return;
    }

    auto action = undoStack.top();
    undoStack.pop();

    action->undo(*document);

    redoStack.push(action);
}

void Editor::redo() {
    if (redoStack.empty()) {
        std::cout << "No actions to redo.\n";
        return;
    }

    auto action = redoStack.top();
    redoStack.pop();

    action->redo(*document);

    undoStack.push(action);
}

std::shared_ptr<Document> Editor::getDocument() const {
    return document;
}
