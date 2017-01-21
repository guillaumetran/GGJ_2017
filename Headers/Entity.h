//
// Created by guillaume on 21/01/17.
//

#ifndef GGJ_ENTITY_H
#define GGJ_ENTITY_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Entity {
public:
    float _x, _y, _dx, _dy, _R, _angle;
    bool _life;
public:
    Entity() {
        this->_life = true;
    }
    virtual ~Entity() {}
    virtual void update() {};

    void settings(int X,int Y,float Angle=0,int radius=10)
    {
        this->_x = X;
        this->_y = Y;
        this->_angle = Angle;
        this->_R = radius;
    }

    void draw(sf::RenderWindow &window) {
        sf::CircleShape circle(_R);
        circle.setFillColor(sf::Color::Black);
        circle.setPosition(_x, _y);
        circle.setOrigin(_R, _R);
        window.draw(circle);
    }
};

#endif //GGJ_ENTITY_H
