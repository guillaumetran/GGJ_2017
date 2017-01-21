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
    float _deg;
    bool  _state;
public:
    Curve(int y, int pos) : _y(pos) {
        _deg = _y;
        _state = true;
    }
    virtual ~Curve() {}

    void draw(sf::RenderWindow &window) {
        sf::CircleShape circle(2);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(_x, _y);
        circle.setOrigin(2, 2);
        window.draw(circle);
    }

    void    update() {
        _deg += 0.05;
        _x = (sin(_deg) * 40) + 50;
    }
};

void setCurve(sf::RenderWindow &window, std::list<Curve *> lCurve, std::list<Curve *> rCurve);

#endif //GGJ_CURVE_H
