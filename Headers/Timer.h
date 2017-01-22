//
// Created by Maxime Killinger on 21/01/2017.
//

#ifndef GGJ_TIMER_H
#define GGJ_TIMER_H

#include <ctime>

class   Timer
{
private:
    int      _points;
    unsigned long       _beginTime;

public:
    int      _record;
    Timer();
    ~Timer();
    Timer(const Timer &other);
    Timer               &operator=(const Timer &other);

    unsigned long       elapsedTime();
    void                reinit();

    int get_points() const {
        return _points;
    };

    void set_points(int _points);

    void set_beginTime(unsigned long _beginTime);
};

#endif //GGJ_TIMER_H
