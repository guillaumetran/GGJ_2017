//
// Created by guillaume on 21/01/17.
//

#ifndef GGJ_CURVE_H
#define GGJ_CURVE_H

#include <cmath>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entity.h"

class Curve : public Entity {
public:
    int   _nextDrop;
    float _deg;
    bool  _left;
public:
    Curve(int pos, bool left) : Entity::Entity(), _left(left) {
        _type = WAVES;
        _y = pos;
        _R = 20;
        _deg = 0;
        _nextDrop = rand() % 150 + 10;
    }
    virtual ~Curve() {}

    void draw(sf::RenderWindow &window) {
    }

    void    update() {
        int offset;

        _nextDrop--;
        if (_nextDrop <= 0) {
            _nextDrop = rand() % 150 + 10;
            _deg = rand() % 100;
            if (!_left)
                _deg *= -1;
        }
        if (_left) {
            offset = 0;
            if (_deg > -40)
                _deg -= 0.5;
        }
        else {
            offset = 480;
            if (_deg < 40)
                _deg += 0.5;
        }
        _x = _deg + offset;
    }
};

void setCurve(sf::RenderWindow &window, std::list<Curve *> lCurve, std::list<Curve *> rCurve, sf::VertexArray lines);

#endif //GGJ_CURVE_H
