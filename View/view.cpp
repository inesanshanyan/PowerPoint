#include "view.hpp"
#include <SFML/Window/Event.hpp>
#include <iostream>

View::View() 
    : window(sf::VideoMode(800, 600), "Presentation Editor"),
      cursorVisible(true) {

    if (!font.loadFromFile("calibri.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    //window.clear(sf::Color(200, 200, 200)); 

    inputText.setFont(font);
    inputText.setCharacterSize(24);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(10.f, 550.f); 
}

View& View::getInstance() {
    static View instance; 
    return instance;
}

bool View::isOpen() const {
    return window.isOpen();
}


void View::update_input_text() {
    inputText.setString(currentCommand);

    if (cursorClock.getElapsedTime().asSeconds() >= 0.5f) {
        cursorVisible = !cursorVisible;
        cursorClock.restart();
    }

    if (cursorVisible) {
        inputText.setString(currentCommand + "_");
    } else {
        inputText.setString(currentCommand);
    }
}

void View::render() {
    window.display();  
}

void View::draw(const std::vector<RenderInfo>& renderInfos) {
    for (const auto& renderInfo : renderInfos) {
        /*std::cout << "RenderInfo - Shape: " << static_cast<int>(renderInfo.shape)
                  << ", X: " << renderInfo.x
                  << ", Y: " << renderInfo.y
                  << ", Width: " << renderInfo.width
                  << ", Height: " << renderInfo.height
                  << ", Color: " << renderInfo.attribute.getColor() << "\n";*/

        switch (renderInfo.shape) {
            case Shape::RECTANGLE:
                drawRectangle(renderInfo);
                break;
            case Shape::TRIANGLE:
                drawTriangle(renderInfo);
                break;
            case Shape::ELLIPSE:
                drawEllipse(renderInfo);
                break;
        }
    }
}

void View::drawRectangle(const RenderInfo& renderInfo) {
    sf::RectangleShape rectangle(sf::Vector2f(renderInfo.width, renderInfo.height));
    rectangle.setPosition(renderInfo.x, renderInfo.y);
    rectangle.setFillColor(convertColor(renderInfo.attribute.getColor()));
    window.draw(rectangle);
}

void View::drawTriangle(const RenderInfo& renderInfo) {
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(renderInfo.x, renderInfo.y));                    
    triangle.setPoint(1, sf::Vector2f(renderInfo.x + renderInfo.width, renderInfo.y)); 
    triangle.setPoint(2, sf::Vector2f(renderInfo.x + renderInfo.width / 2, renderInfo.y - renderInfo.height)); 

    triangle.setFillColor(convertColor(renderInfo.attribute.getColor()));
    window.draw(triangle);
}

void View::drawEllipse(const RenderInfo& renderInfo) {
    sf::CircleShape ellipse(renderInfo.width / 2);
    ellipse.setPosition(renderInfo.x, renderInfo.y);
    ellipse.setScale(1.0f, renderInfo.height / renderInfo.width); 
    ellipse.setFillColor(convertColor(renderInfo.attribute.getColor()));
    window.draw(ellipse);
}

sf::Color View::convertColor(const std::string& color) {
    static const std::unordered_map<std::string, sf::Color> colorMap = {
        {"red", sf::Color::Red},
        {"green", sf::Color::Green},
        {"blue", sf::Color::Blue},
        {"yellow", sf::Color::Yellow},
        {"white", sf::Color::White},
        {"black", sf::Color::Black}
    };

    auto it = colorMap.find(color);
    if (it != colorMap.end()) {
        return it->second;
    }

    return sf::Color::Black;  
}

void View::printRenderInfos(const std::vector<RenderInfo>& renderInfos) {
    float textYOffset = 20.f; 
    float startX = 10.f; 
    float startY = 10.f; 

    for (size_t i = 0; i < renderInfos.size(); ++i) {
        const auto& renderInfo = renderInfos[i];

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(18);
        text.setFillColor(sf::Color::Black);

        std::stringstream ss;
        ss << "Item " << i + 1
           << " - Shape: " << static_cast<int>(renderInfo.shape)
           << ", X: " << renderInfo.x
           << ", Y: " << renderInfo.y
           << ", Width: " << renderInfo.width
           << ", Height: " << renderInfo.height
           << ", Color: " << renderInfo.attribute.getColor();

        text.setString(ss.str());
        text.setPosition(startX, startY + i * textYOffset);

        window.draw(text);
    }
}


const sf::RenderWindow& View::getWindow() const{
    return window;
}

void View::clearWindow() {
    window.clear(sf::Color(200, 200, 200));  
}
