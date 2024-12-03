#include "../headers/Date.h"
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
void Date::setYear(int year) {
    this->year = year;
}
void Date::setMonth(int month) {
    this->month = month;
}
void Date::setDay(int day) {
    this->day = day;
}
void Date::display() const {
    cout << year << "-" << month << "-" << day << endl;
}
