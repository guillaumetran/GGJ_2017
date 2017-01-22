//
// Created by guillaume on 22/01/17.
//

#ifndef GGJ_GAME_H
#define GGJ_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Timer.h"

int game(sf::RenderWindow &window);
void gameover(Timer T, float width, float height, sf::RenderWindow &window);

#endif //GGJ_GAME_H
