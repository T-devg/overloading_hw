#include <iostream>
#include "Time.h"
#include "Bus.h"
using namespace std;

int main()
{
    // Поточний локальний час
    Time_ t1;
    cout << "Current time: ";
    t1.showTime();
    // 12-hour format
    t1.setFormat(false);
    cout << "12-hour format: ";
    t1.showTime();
    // Створення часу вручну
    Time_ t2(23, 59, 58);
    cout << "\nt2: ";
    t2.showTime();
    // +1 секунда
    t2.tickTime();
    cout << "After +1 second: ";
    t2.showTime();
    t2.tickTime();
    cout << "After +1 second: ";
    t2.showTime();
    //Додавання хвилин
    t2 += 5;
    cout << "After +5 minutes: ";
    t2.showTime();
    //Додавання годин
    t2 += 2L;
    cout << "After +2 hours: ";
    t2.showTime();
    //Арифметичний оператор
    Time_ t3 = t2 + 30.0f;
    cout << "t3 = t2 + 30 seconds: ";
    t3.showTime();
    //Порівняння
    if (t3 > t2)
        cout << "t3 is later than t2" << endl;
    if (t2 != t3)
        cout << "t2 and t3 are different" << endl;
    // Віднімання
    t3 -= 10;
    cout << "t3 after -10 minutes: ";
    t3.showTime();
    //Перевірка
    cout << "\nIs t3 valid? " << (t3.valid() ? "yes" : "no") << endl;







    //T-25
    Time_ start(6, 0, 0, true);
    Time_ finish(11, 0, 0, true);

    Bus bus(start, finish, 30, 10);

    cout << "Bus schedule:" << endl;
    cout << "==============================" << endl;

    bus.makeSchedule();
    return 0;
}

