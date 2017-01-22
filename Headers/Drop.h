//
// Created by guillaume on 22/01/17.
//

#ifndef GGJ_DROP_H
#define GGJ_DROP_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "Entity.h"

class Drop : public Entity {
public:
    Drop() {
        _type = DROP;
    }
    virtual ~Drop() {}
    virtual void draw(sf::RenderWindow &window) {
        sf::RectangleShape rectangle(sf::Vector2f(_R, _R));
            rectangle.setFillColor(sf::Color::Red);
            rectangle.setOutlineThickness(5);
            rectangle.setOutlineColor(sf::Color(185, 101, 195, 50));
            rectangle.setOrigin(_R, _R);
            rectangle.setPosition(_x, _y);
            window.draw(rectangle);
        }
};

#endif //GGJ_DROP_H
