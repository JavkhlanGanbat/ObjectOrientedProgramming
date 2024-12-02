#include "../headers/date.hpp"
#include <stdexcept>
#include <iomanip>
#include <sstream>

bool Date::isValidDate(int d, int m, int y) const {
    if (y < 1 || m < 1 || m > 12 || d < 1) {
        return false;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) {
        daysInMonth[1] = 29;
    }

    return d <= daysInMonth[m - 1];
}

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int d, int m, int y) {
    if (!isValidDate(d, m, y)) {
        throw std::invalid_argument("Invalid date");
    }
    day = d;
    month = m;
    year = y;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(int d) {
    if (!isValidDate(d, month, year)) {
        throw std::invalid_argument("Invalid day");
    }
    day = d;
}

void Date::setMonth(int m) {
    if (!isValidDate(day, m, year)) {
        throw std::invalid_argument("Invalid month");
    }
    month = m;
}

void Date::setYear(int y) {
    if (!isValidDate(day, month, y)) {
        throw std::invalid_argument("Invalid year");
    }
    year = y;
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << day << "/"
        << std::setw(2) << std::setfill('0') << month << "/"
        << year;
    return oss.str();
}

bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}
