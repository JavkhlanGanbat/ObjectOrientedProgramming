// Date.cpp
#include "Date.h"
#include <iostream>
Date::Date() : year(0), month(0), day(0) {}
Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}
int Date::getYear() const {
    return year;
}
int Date::getMonth() const {
    return month;
}
int Date::getDay() const {
    return day;
}
void Date::setYear(int newYear) {
    year = newYear;
}
void Date::setMonth(int newMonth) {
    month = newMonth;
}
void Date::setDay(int newDay) {
    day = newDay;
}
void Date::display() const {
    cout << year << "-" << month << "-" << day << endl;
}
