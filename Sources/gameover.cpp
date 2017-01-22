//
// Created by Hugo Lackermaier on 22/01/2017.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Headers/Timer.h"


void gameover(Timer T, float width, float height, sf::RenderWindow &window)
{
    sf::Font font;
    sf::Text txt;
    sf::Text txt_Game_Over;
    font.loadFromFile("../Assets/Neon_Glow.ttf");
    txt.setFont(font);
    txt.setCharacterSize(100);
    txt.setColor(sf::Color::Red);
    txt.setString(std::to_string(T.elapsedTime()));
    txt.setPosition(width / 2 - 100, height / 3 * 1);

    txt.setFont(font);
    txt.setCharacterSize(50);
    txt.setColor(sf::Color::Red);
    txt.setString("GAME OVER");
    txt.setPosition(width / 2 - 100, height / 3 * 2);
    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        window.draw(txt);
        window.draw(txt_Game_Over);
        window.display();
    }
}