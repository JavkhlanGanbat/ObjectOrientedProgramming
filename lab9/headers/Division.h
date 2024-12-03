#pragma once

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

