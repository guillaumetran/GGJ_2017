//
// Created by guillaume on 21/01/17.
//

#ifndef GGJ_SPEAKER_H
#define GGJ_SPEAKER_H

#include "Entity.h"

class Speaker : public Entity{
public:
    int _maxSpeed;
    bool _state;

    Speaker() : Entity() {
        _type = SPEAKER;
        _maxSpeed = 5;
        _state = true;
    }
    virtual ~Speaker() {}

    void update() {
        if (_state && _R >= 25)
            _state = false;
        if (!_state && _R <= 5)
            _state = true;
        if (_state)
            _R++;
        else
            _R--;
        _y += 5;
        if (_y >= 720)
            _life = false;
    }

    void draw(sf::RenderWindow &window) {
        sf::CircleShape circle(_R);

        circle.setPosition(_x, _y);
        circle.setOrigin(_R, _R);
        circle.setFillColor(sf::Color(_R * 10, 140, _R * 10));
        circle.setOutlineThickness(25 - _R);
        circle.setOutlineColor(sf::Color(_R * 10, 140, _R * 10, 30));
        window.draw(circle);
        circle.setOutlineThickness(15 - _R);
        circle.setOutlineColor(sf::Color(_R * 10, 140, _R * 10, 60));
        window.draw(circle);
    }
};

#endif //GGJ_SPEAKER_H
