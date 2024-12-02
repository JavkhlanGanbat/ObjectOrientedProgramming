// Division.h
#ifndef DIVISION_H
#define DIVISION_H

#include <string>
#include <iostream>
using namespace std;
class Division {
private:
    string divisionName;

public:
    string getDivisionName() const;
    void setDivisionName(string divisionName);
};

#endif // DIVISION_H
