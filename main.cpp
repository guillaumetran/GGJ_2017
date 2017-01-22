#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "Headers/Player.h"
#include "Headers/Speaker.h"
#include "Headers/Curve.h"
#include "Headers/Timer.h"

using namespace sf;

const int W = 480;
const int H = 720;

bool isCollide(Entity *a,Entity *b)
{
    return (b->_x - a->_x)*(b->_x - a->_x)+
           (b->_y - a->_y)*(b->_y - a->_y)<
           (a->_R + b->_R)*(a->_R + b->_R);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(W,H),"GGJ 2017");
    window.setFramerateLimit(60);
    std::list<Curve *> lCurve;
    std::list<Curve *> rCurve;
    std::list<Entity *> entities;
    Player  *player = new Player();
    unsigned long   k(0);
    Timer           T;
    sf::Text        score;
    sf::Font        scoreType;

    std::string str = std::to_string(k);
    score.setString(str);
    scoreType.loadFromFile("../Assets/score.ttf");
    score.setFont(scoreType);
    score.setCharacterSize(32);
    score.setFillColor(sf::Color::Red);
    player->settings(W/2, H * 3/4);
    for (int i = 0; i < 15; i++) {
        Speaker *speaker = new Speaker();
        speaker->settings((rand() % (W - 200)) + 100, rand() % H, 0, rand() % 20 + 5);
        entities.push_back(speaker);
    }
    for (int i = 0; i < 20; i++) {
        Curve *_curve = new Curve(i, i * H / 20, true);
        lCurve.push_back(_curve);
    }
    for (int i = 0; i < 20; i++) {
        Curve *_curve = new Curve(i, i * H / 20, false);
        _curve->_x = W;
        rCurve.push_back(_curve);
    }
    entities.push_back(player);
    while(window.isOpen()){
        sf::Event event;

        window.clear(sf::Color(228, 231, 255));
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        getMovement(player);
        for(auto a:entities)
            for(auto b:entities) {
                if (a->_type == Entity::PLAYER && b->_type == Entity::SPEAKER)
                    if ( isCollide(a,b) )
                    {
                        T.reinit();
                        k = 0;
                        str = std::to_string(k);
                        score.setString(str);
                        player->settings(W/2, H * 3/4);
                    }
            }
        for(auto i = entities.begin(); i != entities.end();) {
            Entity *e = *i;

            e->update();
            if (!e->_life) {
                if (e->_type == Entity::SPEAKER) {
                    Speaker *speaker = new Speaker();
                    speaker->settings((rand() % (W - 200)) + 100, rand() % 50, 0, rand() % 20 + 5);
                    entities.push_back(speaker);
                }
                i = entities.erase(i);
                delete e;
            }
            else {
                e->draw(window);
                i++;
            }
        }
        if (T.elapsedTime() > k)
        {
            k = T.elapsedTime(1000);
            str = std::to_string(k);
            score.setString(str);
        }
        setCurve(window, lCurve, rCurve);
        window.draw(score);
        window.display();
    }
    return 0;
}
