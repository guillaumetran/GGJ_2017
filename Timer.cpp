//
// Created by Maxime Killinger on 21/01/2017.
//

#include "Headers/Timer.h"

Timer::Timer()
{
    reinit();
}

Timer::Timer(const Timer &other)
{
    this->_beginTime = other._beginTime;
}

Timer::~Timer()
{
}

Timer&      Timer::operator=(const Timer &other)
{
    this->_beginTime = other._beginTime;
    return (*this);
}

bool        Timer::isTimeout(unsigned long seconds)
{
    return (seconds - 1) >= elapsedTime();
}

unsigned long   Timer::elapsedTime()
{
    return ((unsigned long) clock() - _beginTime) / (CLOCKS_PER_SEC / 100);
}

void        Timer::reinit()
{
    _beginTime = clock();
}
