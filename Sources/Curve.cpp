//
// Created by guillaume on 21/01/17.
//

#include <list>
#include "../Headers/Curve.h"

void setCurve(sf::RenderWindow &window, std::list<Curve *> lCurve, std::list<Curve *> rCurve, sf::VertexArray lines) {
    int z = 0;

    lines[21].position = sf::Vector2f(440, 1320);
    for(auto i = lCurve.begin(); i != lCurve.end();)
    {
        Curve *c = *i;
        c->update();
        lines[z].color = sf::Color(140, z * 11, z * 11);
        lines[z++].position = sf::Vector2f(c->_x + 40, c->_y + 40);
        i++;
    }
    window.draw(lines);
    z = 0;
    for(auto i = rCurve.begin(); i != rCurve.end();)
    {
        Curve *c = *i;
        c->update();
        lines[z].color = sf::Color(140, z * 11, z * 11);
        lines[z++].position = sf::Vector2f(c->_x - 40, c->_y - 40);
        i++;
    }
    window.draw(lines);
}