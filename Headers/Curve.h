//
// Created by guillaume on 21/01/17.
//

#ifndef GGJ_CURVE_H
#define GGJ_CURVE_H

#include <cmath>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Curve {
public:
    int   _x;
    int   _y;
    int   _deg;
    bool  _state;
public:
    Curve(int y) : _y(y) {
        _deg = _y;
        _state = true;
    }
    virtual ~Curve() {}

    void draw(sf::RenderWindow &window) {
        sf::CircleShape circle(2);
        circle.setFillColor(sf::Color::Cyan);
        circle.setPosition(_x, _y);
        circle.setOrigin(2, 2);
        window.draw(circle);
    }

    void    update() {
        /*if (_deg >= 45)
            _state = false;
        if (_deg <= 0)
            _state = true;
        if (_state)*/
            _deg++;
        /*else
            _deg--;*/
        _x = (sin(_deg) * 40) + 50;
    }
};

#endif //GGJ_CURVE_H
