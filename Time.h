#pragma once
class Time_
{
    int hour;
    int minutes;
    int seconds;
    bool format;// true = utc (24-hours),    false = am/pm (12-hours),  Тільки для виведення часу на екран
public:
    Time_(); // Поточний локальний час
    Time_(int hour, int minutes, int seconds, bool format = true);
    Time_(const Time_& obj); //Визначити: чи потрібен Конструктор Копіювання?
    Time_& operator = (const Time_& obj); // Визначити: чи потрібен Оператор Присвоювання?
    ~Time_(); // Визначити: чи потрібен Деструктор?

    void setHour(int hour);
    int getHour()const;
    void setMinutes(int minutes);
    int getMinutes()const;
    void setSeconds(int seconds);
    int getSeconds()const;
    void setFormat(bool format);
    bool getFormat()const;

    bool valid()const; //Перевірка на правильність данних
    void tickTime(); //Додавання однієї секунди
    void untickTime(); //Віднімання однієї секунди
    void showTime()const; //Демонстрація часу на екран з урахуванням встановленного формату

    //--------- Оператори порівняння (Comparison operators ) ---------
    bool operator == (const Time_& obj)const&;
    bool operator != (const Time_& obj)const&;
    bool operator > (const Time_& obj)const&;
    bool operator < (const Time_& obj)const&;
    bool operator >= (const Time_& obj)const&;
    bool operator <= (const Time_& obj)const&;

    //--------- Оператори присвоювання (Assignment operators) ---------
    Time_& operator += (float s);	// add seconds
    Time_& operator -= (float s);
    Time_& operator += (int m);	// add minutes
    Time_& operator -= (int m);
    Time_& operator += (long h);	// add hours
    Time_& operator -= (long h);

    //--------- Арифметичні оператори (Arithmetic operators) ---------
    Time_ operator + (float s)const&;	// add seconds
    Time_ operator - (float s)const&;
    Time_ operator + (int m)const&; // add minutes
    Time_ operator - (int m)const&;
    Time_ operator + (long h)const&; // add hours
    Time_ operator - (long h)const&;

};
