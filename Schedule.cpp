//
// Created by Ольга on 20.09.2026.
//

#include "Schedule.h"
#include <iostream>
using namespace std;
 Schedule::Schedule(Time_ start, int lessonDur, int shortBr, int longBr, int longAfter, int lessons) {
  this->startTime = start;
  this->lessonDuration = lessonDur;
  this->shortBreak = shortBr;
  this->longBreak = longBr;
  this->longBreakAfter = longAfter;
  this->totalLessons = lessons;
}

 void Schedule::generateSchedule() const {
  Time_ current = startTime;
  for (int i = 0; i < totalLessons; i++) {
   current = current + lessonDuration;
   cout << i+1 << " урок: ";
   current.showTime() ;
   cout << " - " << lessonDuration << endl;
   if ( i + 1 == longBreakAfter) {
    cout << longBreak << " хвилин довгої перерви " << endl;
    current = current + longBreak;
   }
   else {

    cout << shortBreak << " хвилин перерва " << endl;
    current = current + shortBreak;

   }
  }
}