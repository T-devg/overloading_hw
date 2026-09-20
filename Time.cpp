//
// Created by Ольга on 16.09.2026.
//
#include <ctime>
#include "iostream"
#include "Time.h"
using namespace std;

Time_::Time_() {
    tm info ={};
    auto curent = time(0);
#if dateWindows == 1
    localtime_s(&info, &curent ); //VS
#elif dateWindows == 0
    tm* p = localtime(&curent);// CLION
    info = *p;
#endif

    hour = info.tm_hour;
    minutes = info.tm_min;
    seconds = info.tm_sec;
    format = true;
}

Time_::Time_(int hour, int minutes, int seconds, bool format) {
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
    this->format = format;
}

Time_::Time_(const Time_ &obj) {
    //В даному випадку Конструктор Копіювання не потрібен , оскільки немає динамічної памяті
   // (але краще прописати щоб згадати)
    this->hour = obj.hour;
    this->minutes = obj.minutes;
    this->seconds = obj.seconds;
    this->format = obj.format;
}

Time_ & Time_::operator=(const Time_ &obj) {
    this->hour = obj.hour;
    this->minutes = obj.minutes;
    this->seconds = obj.seconds;
    this->format = obj.format;
    return *this;
}

Time_::~Time_() {
}


void Time_::setHour(int hour) {
    if (hour >= 0 && hour <= 23) {
        this->hour = hour;
    }
}

int Time_::getHour() const {
    return hour;
}

void Time_::setMinutes(int minutes) {
    if (minutes >= 0 && minutes <= 59) {
        this->minutes = minutes;
    }
}

int Time_::getMinutes() const {
    return minutes;
}

void Time_::setSeconds(int seconds) {
    if (seconds >= 0 && seconds <= 59) {
        this->seconds = seconds;
    }
}

int Time_::getSeconds() const {
    return seconds;
}

void Time_::setFormat(bool format) {
    this->format = format;
}

bool Time_::getFormat() const {
    return format;
}

bool Time_::valid() const {
    if ((hour >= 0 && hour <= 23) && (minutes >= 0 && minutes <=59) && (seconds >= 0 && seconds <= 59)) {
        return true;
    }
    else {
        return false;
    }
}

void Time_::tickTime() {
    seconds++;
    if (seconds >=60) {
        minutes++;
        seconds = 0;
        if (minutes >= 60) {
            hour++;
            minutes = 0;
            if (hour >= 24) {
                hour=0;
            }

        }
    }
}

void Time_::untickTime() {
    seconds--;
    if (seconds < 0) {
        seconds = 59;
        minutes--;
        if (minutes < 0) {
            minutes = 59;
            hour--;
            if (hour < 0) {
                hour = 23;
            }
        }
    }
}

void Time_::showTime() const {
    if (format == true) {
        cout << "Hours: " << hour << endl;
        cout << "Minutes: " << minutes << endl;
        cout << "Seconds: " << seconds << endl;
    }
    else if (format == false){
        char* half;
        int h = hour;
        if (h == 0) {
            h = 12;
            half = "AM";
        }
        else if (h < 12) {
            half = "AM";
        }
        else if (h == 12) {
            half = "PM";
        }
        else {
            h -= 12;
            half = "PM"; //друга половина
        }
        cout << "Hours: " << h << " " << half << endl;
        cout << "Minutes: " << minutes << endl;
        cout << "Seconds: " << seconds << endl;
    }
    cout << "==================================" << endl;
}

bool Time_::operator==(const Time_ &obj) const & {
    if (hour == obj.hour && minutes == obj.minutes && seconds == obj.seconds) {
        return true;
    }
    else {
        return false;
    }
}

bool Time_::operator!=(const Time_ &obj) const & {
    return !(*this == obj);
}

bool Time_::operator>(const Time_ &obj) const & {
    if (hour != obj.hour) {
        return hour > obj.hour;
    }
    if (minutes != obj.minutes) {
        return minutes > obj.minutes;
    }
    return seconds > obj.seconds;
}

bool Time_::operator<(const Time_ &obj) const & {
    if (*this != obj && !(*this>obj)) {
        return true;
    }
    else {
        return false;
    }
}

bool Time_::operator>=(const Time_ &obj) const & {
    return !(*this < obj);
}

bool Time_::operator<=(const Time_ &obj) const & {
    return !(*this > obj);
}

Time_ & Time_::operator+=(float s) {
    if (s>0) {
        for (int i = 0; i < s; i++ ) {
            this->tickTime();
        }
    }
    return *this;
}

Time_ & Time_::operator-=(float s) {
    if (s > 0) {
        for (int i = 0; i < s; i++ ) {
            this->untickTime();
        }
    }
    return *this;

}

Time_ & Time_::operator+=(int m) {
    if (m>0) {
        m = m * 60;
        for (int i = 0; i < m; i++) {
            this->tickTime();
        }
    }
    return *this;

}

Time_ & Time_::operator-=(int m) {
    if (m>0) {
        m = m * 60;
        for (int i = 0; i < m; i++) {
            this->untickTime();
        }
    }
    return *this;
}

Time_ & Time_::operator+=( long h) {
    if (h > 0) {
        h = h * 3600;
        for (int i =0 ; i < h; i++) {
            this->tickTime();
        }
    }
    return *this;
}

Time_ & Time_::operator-=(long h) {
    if (h > 0) {
        h = h * 3600;
        for (int i =0 ; i < h; i++) {
            this->untickTime();
        }
    }
    return *this;
}

Time_ Time_::operator+(float s) const & {
    Time_ tmp = *this;
    tmp += s;
    return tmp;
}

Time_ Time_::operator-(float s) const & {
    Time_ tmp = *this;
    tmp -= s;
    return tmp;
}

Time_ Time_::operator+(int m) const & {
    Time_ tmp = *this;
    tmp += m;
    return tmp;
}

Time_ Time_::operator-(int m) const & {
    Time_ tmp = *this;
    tmp -= m;
    return tmp;
}

Time_ Time_::operator+(long h) const & {
    Time_ tmp = *this;
    tmp += h;
    return tmp;
}

Time_ Time_::operator-(long h) const & {
    Time_ tmp = *this;
    tmp -= h;
    return tmp;
}
