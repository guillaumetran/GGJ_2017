//
// Created by Maxime Killinger on 21/01/2017.
//

#include <iostream>
#include "../Headers/Timer.h"

Timer::Timer()
{
    reinit();
    _points = 0;
}

Timer::Timer(const Timer &other)
{
    this->_beginTime = other._beginTime;
    _points = 0;
}

Timer::~Timer()
{
}

void Timer::set_beginTime(unsigned long _beginTime) {
    Timer::_beginTime = _beginTime;
}

void Timer::set_points(int _points) {
    Timer::_points = _points;
}

Timer&      Timer::operator=(const Timer &other)
{
    this->_beginTime = other._beginTime;
    return (*this);
}

unsigned long   Timer::elapsedTime()
{
    return ((unsigned long) clock() - this->_beginTime) / (CLOCKS_PER_SEC / 1000);
}

void        Timer::reinit()
{
    this->_beginTime = clock();
}
