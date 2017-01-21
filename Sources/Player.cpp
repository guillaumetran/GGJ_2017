//
// Created by guillaume on 22/01/17.
//

#include <SFML/Window/Keyboard.hpp>
#include "../Headers/Player.h"

using namespace sf;

void getMovement(Player *player) {
    player->_move = false;
    if (Keyboard::isKeyPressed(Keyboard::Right)) { player->_angle = 0; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Left)) { player->_angle = 180; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Up)) { player->_angle = 270; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Down)) { player->_angle = 90; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
    { player->_angle = 315; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
    { player->_angle = 225; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right))
    { player->_angle = 45; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left))
    { player->_angle = 135; player->_move = true; }
}