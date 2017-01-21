#include <SFML/Graphics.hpp>
#include <list>
#include "Headers/Player.h"
#include "Headers/Speaker.h"
#include "Headers/Curve.h"

using namespace sf;

const int W = 480;
const int H = 720;

void getMovement(Player *player) {
    player->_move = false;
    if (Keyboard::isKeyPressed(Keyboard::Right)) { player->_angle = 0; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Left)) { player->_angle = 180; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Up)) { player->_angle = 270; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Down)) { player->_angle = 90; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
    { player->_angle = 315; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
    { player->_angle = 225; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right))
    { player->_angle = 45; player->_move = true; }
    if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left))
    { player->_angle = 135; player->_move = true; }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(W,H),"GGJ 2017");
    window.setFramerateLimit(60);

    std::list<Entity *> entities;

    Player  *player = new Player();
    player->settings(W/2, H/2);

    for (int i = 0; i < 15; i++) {
        Speaker *speaker = new Speaker();
        speaker->settings(rand() % W , rand() % H, 0, rand() % 20 + 5);
        entities.push_back(speaker);
    }

    std::list<Curve *> curve;
    for (int i = 0; i < H; i++) {
        Curve *_curve = new Curve(i);
        curve.push_back(_curve);
    }

    entities.push_back(player);

    while(window.isOpen()){
        sf::Event event;

        window.clear(sf::Color::White);
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        getMovement(player);

        for(auto i = entities.begin(); i != entities.end();)
        {
            Entity *e = *i;

            e->update();
            if (e->_life==false) {
                i=entities.erase(i);
                delete e;
            }
            else {
                e->draw(window);
                i++;
            }
        }
        for(auto i = curve.begin(); i != curve.end();)
        {
            Curve *c = *i;
            c->update();
            c->draw(window);
            i++;
        }

        window.display();
    }
    return 0;
}
