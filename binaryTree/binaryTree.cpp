#include "_Tree_drawing.h"
#include "_Tree.h"
#include <SFML/Graphics.hpp>
#include <iostream>


int main() {
    
    sf::Font font;
    if (!font.loadFromFile("CyrilicOld.TTF"))
        return -1;

    auto tree = std::make_shared<_Tree<int, int>>(_Tree<int, int>());
    _Tree_drawing<int, int> drawer(tree, font);

    sf::RenderWindow window(sf::VideoMode(700, 700), "Tree");
    window.setFramerateLimit(60);
  
    while (window.isOpen()) {
        sf::Event event;
      
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    std::cout << "add value:";
                    int value;
                    std::cin >> value;
                    tree->_Emplace(value);
                }

                if (event.key.code == sf::Keyboard::D) {
                    std::cout << "Deleat by key:";
                    int key;
                    std::cin >> key;
                    tree->_Extract(key);
                }
            }
        }
         
  
        window.clear();
        window.draw(drawer);

        window.display();

    }
    return 0;
}