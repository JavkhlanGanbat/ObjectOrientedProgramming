#include "../headers/Date.hpp"

Date::Date() : year(1970), month(1), day(1) {}

Date::Date(int day, int month, int year) {
    setDate(day, month, year);
}

Date::Date(const Date& date) {
    setDate(date.getDay(), date.getMonth(), date.getYear());
}

Date::Date(const string& date) {
    parseFromString(date);
}

void Date::setDate(int day, int month, int year) {
    if (!(day >= 1 && day <= 31)) throw out_of_range("Day not within range.");
    if (!(month >= 1 && month <= 12)) throw out_of_range("Month not within range.");
    if (!(year >= 1970)) throw out_of_range("Year not within range.");
    setYear(year);
    setMonth(month);
    setDay(day);
}

string Date::getFormattedDate() const {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

int Date::getYear() const { return year; }

int Date::getMonth() const { return month; }

int Date::getDay() const { return day; }

void Date::setDay(int day) {
    if (day >= 1 && day <= 31) {
        this->day = day;
    }
}

void Date::setMonth(int month) {
    if (month >= 1 && month <= 12) {
        this->month = month;
    }
}

void Date::setYear(int year) {
    if (year >= 1900) {
        this->year = year;
    }
}

void Date::parseFromString(const string& date) {
    int d = 0, m = 0, y = 0;
    size_t i = 0;

    while (i < date.size() && date[i] != '/') {
        d = d * 10 + (date[i] - '0');
        i++;
    }

    i++;
    while (i < date.size() && date[i] != '/') {
        m = m * 10 + (date[i] - '0');
        i++;
    }

    i++;
    while (i < date.size()) {
        y = y * 10 + (date[i] - '0');
        i++;
    }

    if (d == 0 || m == 0 || y == 0) throw invalid_argument("Date not in correct format D/M/Y");
    setDate(d, m, y);
}
