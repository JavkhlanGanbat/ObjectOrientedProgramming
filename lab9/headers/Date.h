#pragma once    

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

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);

    void display() const;
};
