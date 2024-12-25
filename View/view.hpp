#pragma once

#include <SFML/Graphics.hpp>
#include "../Document/document.hpp"
#include <functional>
#include <string>
#include <unordered_map>
#include <sstream>

class View {
public:
    static View& getInstance();

    void render();
    bool isOpen() const;
    void draw(const std::vector<RenderInfo>& renderInfos);
    void printRenderInfos(const std::vector<RenderInfo>& renderInfos);

    const sf::RenderWindow& getWindow() const;
    void clearWindow();

private:
    View();  
    View(const View&) = delete;            
    View& operator=(const View&) = delete; 

    sf::RenderWindow window;
    sf::Font font;
    sf::Text inputText;
    std::string currentCommand;
    bool cursorVisible;
    sf::Clock cursorClock;

    void update_input_text();
    void drawRectangle(const RenderInfo& renderInfo);
    void drawTriangle(const RenderInfo& renderInfo);
    void drawEllipse(const RenderInfo& renderInfo);

    sf::Color convertColor(const std::string& color);
};
