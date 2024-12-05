#pragma once

#include <string>
#include <stdexcept>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

public:
    // baiguulagch functsuud, huulagch
    Date();
    Date(int day, int month, int year);
    Date(const Date& date);
    Date(const string& date);

    void setDate(int day, int month, int year);

    // d/m/y format ruu shiljuuleh
    string getFormattedDate() const;

    // getter, setter
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    void parseFromString(const string& date);
};
