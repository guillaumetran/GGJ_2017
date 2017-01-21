//
// Created by guillaume on 21/01/17.
//

#include <list>
#include "../Headers/Curve.h"

void setCurve(sf::RenderWindow &window, std::list<Curve *> lCurve, std::list<Curve *> rCurve) {
    for(auto i = lCurve.begin(); i != lCurve.end();)
    {
        Curve *c = *i;
        c->update();
        c->draw(window);
        i++;
    }
    for(auto i = rCurve.begin(); i != rCurve.end();)
    {
        Curve *c = *i;
        c->update();
        c->draw(window);
        i++;
    }
}