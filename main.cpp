#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(640,480,32),"GGJ 2017");
    sf::Font font;
    font.loadFromFile("../OpenSans-Bold.ttf");
    sf::Text text("Hello World", font, 11);
    text.setCharacterSize(32);
    text.setPosition(window.getSize().x/2 - text.getGlobalBounds().width/2,
                     window.getSize().y/2 - text.getGlobalBounds().height/2);
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setSize(sf::Vector2f(100, 100));
    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
            window.clear(sf::Color::Magenta);
            window.draw(text);
            window.draw(rectangle);
            rectangle.move(1, 1);
            window.display();

        }
    }

    return 0;
}