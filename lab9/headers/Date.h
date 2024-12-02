// Date.h
#ifndef DATE_H
#define DATE_H
using namespace std;
class Date {
private:
    int year;
    int month;
    int day;

public:
    Date();
    Date(int year, int month, int day);

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void setYear(int newYear);
    void setMonth(int newMonth);
    void setDay(int newDay);

    void display() const;
};

#endif // DATE_H
