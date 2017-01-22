#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Headers/Game.h"
#include "Headers/Menu.h"

using namespace sf;

const int W = 480;
const int H = 720;

int main() {
    sf::RenderWindow window(sf::VideoMode(W,H),"GGJ 2017");
    window.setFramerateLimit(60);
    Menu menu(window.getSize().x, window.getSize().y);

    sf::SoundBuffer main_sound;
    main_sound.loadFromFile("../Music/menu_sound.ogg");
    sf::Sound Sound(main_sound);
    Sound.setVolume(70);
    Sound.play();

    while(window.isOpen()){
        sf::Event event;

        window.clear(sf::Color::Black);

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            sf::SoundBuffer music;
            music.loadFromFile("../Music/move_button.ogg");
            sf::Sound move(music);
            move.setVolume(70);
            move.play();

            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;
                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0: {
                                    Sound.pause();
                                    sf::SoundBuffer music_main;
                                    music_main.loadFromFile("../Music/music.ogg");
                                    sf::Sound main(music_main);
                                    main.setVolume(70);
                                    main.play();
                                    game(window);
                                }
                                case 1:
                                    window.close();
                                    break;
                            }
                    }
            }
        }
        menu.draw(window);
        window.display();
    }
    return 0;
}
