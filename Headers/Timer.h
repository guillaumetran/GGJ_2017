//
// Created by Maxime Killinger on 21/01/2017.
//

#ifndef GGJ_TIMER_H
#define GGJ_TIMER_H

#include <ctime>

class   Timer
{
private:
    unsigned long       _beginTime;

public:
    Timer();
    ~Timer();
    Timer(const Timer &other);
    Timer               &operator=(const Timer &other);

    unsigned long       elapsedTime();
    void                reinit();
};

#endif //GGJ_TIMER_H
