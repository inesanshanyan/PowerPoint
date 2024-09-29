#pragma once 

#include <iostream>
#include <string>

namespace cli{
    class Command {
    public:
        virtual void execute() = 0;
        virtual ~Command() = default;
    };

    //slide commands
    class AddSlideCommand : public Command {
    public:
        void execute() override;
    };

    class RemoveSlideCommand : public Command {
    public:
        RemoveSlideCommand(std::size_t index): index(index) { }
        void execute() override;
    private:
        std::size_t index;
    };

    //shape commands
    class AddRectangleCommand : public Command {
    public:
        AddRectangleCommand(int x, int y, int width, int height) 
            : x(x), y(y), width(width), height(height) { }
        void execute() override;
    private:
        int x, y, width, height;
    };

    class AddSquareCommand : public Command {
    public:
        AddSquareCommand(int x, int y, int size) 
            : x(x), y(y), size(size) { }
        void execute() override;
    private:
        int x, y, size;
    };

    class AddCircleCommand : public Command {
    public:
        AddCircleCommand(int x, int y, int size) 
            : x(x), y(y), size(size) { }
        void execute() override;
    private:
        int x, y, size;
    };

    class RemoveRectangleCommand : public Command {
    public:
        RemoveRectangleCommand(std::size_t index) : index(index) { }
        void execute() override;
    private:
        std::size_t index;
    };

    class RemoveSquareCommand : public Command {
    public:
        RemoveSquareCommand(std::size_t index) : index(index) { }
        void execute() override;
    private:
        std::size_t index;
    };

    class RemoveCircleCommand : public Command {
    public:
        RemoveCircleCommand(std::size_t index) : index(index) { }
        void execute() override;
    private:
        std::size_t index;
    };


    //text commands
    class AddTextCommand : public Command {
    public:
        AddTextCommand(std::size_t x, std::size_t y, std::string text)
             : x(x), y(y), text(text) { }
        void execute() override;
    private:
        std::string text;
        std::size_t x, y;
    };

    //control commands
    class PlayCommand : public Command {
    public:
        PlayCommand(std::size_t startIndex) : startIndex(startIndex) { }
        void execute() override;
    private:
        std::size_t startIndex;
    };

    class StopCommand : public Command {
    public:
        void execute() override;
    };

    class NextCommand : public Command {
    public:
        void execute() override;
    };

    class PrevCommand : public Command {
    public:
        void execute() override;
    };

    class GoToSlideCommand : public Command {
    public:
        GoToSlideCommand(std::size_t index): index(index) { }
        void execute() override;
    private:
        std::size_t index;
    };

    class PauseCommand : public Command {
    public:
        void execute() override;
    };

    class HelpCommand : public Command {
    public:
        void execute() override;
    };

    class ExitCommand : public Command {
    public:
        void execute() override;
    };

}
