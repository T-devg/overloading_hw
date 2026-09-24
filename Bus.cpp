//
// Created by Ольга on 23.09.2026.
//

#include "Bus.h"
Bus::Bus(const Time_& start,const Time_& finish,int routeTime=30,int restTime=10)
{
    this->start = start;
    this->finish = finish;
    this->routeTime = routeTime;
    this->restTime = restTime;
}


void Bus::makeSchedule() const {
    Time_ departure = start;
    Time_ arrival;
    while (true) {
        arrival = departure + routeTime;
        if (arrival > finish) {
            break;
        }
        cout << departure << "  " << arrival << endl;
        departure = arrival + restTime;
        if (departure > finish) {
            break;
        }
    }
}
