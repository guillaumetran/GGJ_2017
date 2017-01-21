//
// Created by guillaume on 21/01/17.
//

#ifndef GGJ_ENTITY_H
#define GGJ_ENTITY_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Entity {
public:
    enum TYPE {
        PLAYER,
        SPEAKER,
        WAVES
    };
    float _x, _y, _dx, _dy, _R, _angle;
    bool _life;
    TYPE _type;

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

    virtual void draw(sf::RenderWindow &window) {
        sf::CircleShape circle(_R);
        if (this->_type == PLAYER) {
            circle.setFillColor(sf::Color::Red);
        }
        else {
            circle.setFillColor(sf::Color(185, 101, 195));
            circle.setOutlineThickness(25 - _R);
            circle.setOutlineColor(sf::Color(185, 101, 195, 50));
        }
        circle.setPosition(_x, _y);
        circle.setOrigin(_R, _R);
        window.draw(circle);
    }
};

#endif //GGJ_ENTITY_H
