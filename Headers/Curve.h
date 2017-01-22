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
    int   _nextDrop;
    float _deg;
    bool  _left;
public:
    Curve(int y, int pos, bool left) : _y(pos), _left(left) {
        _deg = 0;
        _nextDrop = rand() % 150 + 10;
    }
    virtual ~Curve() {}

    void draw(sf::RenderWindow &window) {
        sf::CircleShape circle(4);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(_x, _y);
        circle.setOrigin(2, 2);
        window.draw(circle);
    }

    void    update() {
        int offset;

        _nextDrop--;
        if (_nextDrop <= 0) {
            _nextDrop = rand() % 150 + 10;
            _deg = rand() % 70;
            if (!_left)
                _deg *= -1;
        }
        if (_left) {
            offset = 0;
            if (_deg > 0)
                _deg -= 0.5;
        }
        else {
            offset = 480;
            if (_deg < 0)
                _deg += 0.5;
        }
        _x = _deg + offset;
    }
};

void setCurve(sf::RenderWindow &window, std::list<Curve *> lCurve, std::list<Curve *> rCurve);

#endif //GGJ_CURVE_H
