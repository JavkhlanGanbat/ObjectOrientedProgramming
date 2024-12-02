#pragma once

#include <string>

class Date {
private:
    int day;
    int month;
    int year;

    bool isValidDate(int d, int m, int y) const;

public:
    Date();
    Date(int d, int m, int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    std::string toString() const;

    bool operator==(const Date& other) const;
};
