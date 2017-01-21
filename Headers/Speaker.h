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
            _y = 0;
        /*_life = false;*/
    }
};

#endif //GGJ_SPEAKER_H