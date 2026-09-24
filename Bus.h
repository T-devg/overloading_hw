//
// Created by Ольга on 23.09.2026.
//

#ifndef OVERLOADING_HW_BUS_H
#define OVERLOADING_HW_BUS_H
#include "Time.h"

class Bus {
private:
    Time_ start;
    Time_ finish;
    int routeTime;
    int restTime;

public:
    Bus(const Time_& start,
        const Time_& finish,
        int routeTime,
        int restTime);

    void makeSchedule() const;

};



#endif //OVERLOADING_HW_BUS_H
