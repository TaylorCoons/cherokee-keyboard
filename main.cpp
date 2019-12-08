
#include <SFML/Graphics.hpp>
#include <iostream>
#include "KeyEmulator.h"

int main() {
    KeyEmulator keyEm;
   
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                std::cout << "Key Pressed" << std::endl;  
                std::cout << "Code: " << event.key.code << std::endl;              
            }
        }
        
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
