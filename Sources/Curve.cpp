//
// Created by guillaume on 21/01/17.
//

#include <list>
#include "../Headers/Curve.h"

void setCurve(sf::RenderWindow &window, std::list<Curve *> lCurve, std::list<Curve *> rCurve, sf::VertexArray lines) {
    sf::Color color;
    int z = 0;

    lines[21].position = sf::Vector2f(440, 1320);
    for(auto i = lCurve.begin(); i != lCurve.end();)
    {
        Curve *c = *i;
        c->update();
        if (c->_nextDrop < 40)
            color = sf::Color::Red;
        else if (c->_nextDrop < 80)
            color = sf::Color(255, 176, 95);
        else if (c->_nextDrop < 120)
            color = sf::Color::Yellow;
        else if (c->_nextDrop < 160)
            color = sf::Color::Green;
        else if (c->_nextDrop < 200)
            color = sf::Color::Cyan;
        else
            color = sf::Color::Blue;
        lines[z].color = color;
        lines[z++].position = sf::Vector2f(c->_x + 40, c->_y + 40);
        i++;
    }
    window.draw(lines);
    z = 0;
    for(auto i = rCurve.begin(); i != rCurve.end();)
    {
        Curve *c = *i;
        c->update();

        if (c->_nextDrop < 20)
            color = sf::Color::Red;
        else if (c->_nextDrop < 40)
            color = sf::Color(255, 176, 95);
        else if (c->_nextDrop < 60)
            color = sf::Color::Yellow;
        else if (c->_nextDrop < 80)
            color = sf::Color::Green;
        else if (c->_nextDrop < 100)
            color = sf::Color::Cyan;
        else
            color = sf::Color::Blue;

        lines[z].color = color;
        lines[z++].position = sf::Vector2f(c->_x - 40, c->_y - 40);
        i++;
    }
    window.draw(lines);
}