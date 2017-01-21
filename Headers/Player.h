//
// Created by guillaume on 21/01/17.
//

#ifndef GGJ_PLAYER_H
#define GGJ_PLAYER_H

#include <iostream>
#include <cmath>
#include "Entity.h"

class Player : public Entity {
public:
    bool _move;
public:
    Player() : Entity() {
        _type = PLAYER;
    }

    virtual ~Player() {}

    void update() {
        if (_move) {
            this->_dx += cos(_angle * 0.017453f) * 0.7;
            this->_dy += sin(_angle * 0.017453f) * 0.7;
        }
        else {
            this->_dx *= 0.95;
            this->_dy *= 0.95;
        }
        int maxSpeed=10;
        float speed = sqrt(_dx * _dx + _dy * _dy);
        if (speed>maxSpeed) {
            _dx *= maxSpeed/speed;
            _dy *= maxSpeed/speed;
        }
        _x += _dx;
        _y += _dy;

        if (_x > 460 || _x < 20)
            _x -= _dx;
        if (_y > 700 || _y < 20)
            _y -= _dy;
    }

    void draw(sf::RenderWindow &window) {
        sf::CircleShape circle(_R);

        circle.setFillColor(sf::Color(58, 166, 212));
        circle.setPosition(_x, _y);
        circle.setOrigin(_R, _R);
        window.draw(circle);
    }
};

void getMovement(Player *player);

#endif //GGJ_PLAYER_H
