#pragma once

#include <string>
using namespace std;

class Division {
private:
    string divname;

public:
    Division(const string& divname);
    Division(const Division& division);

    string getDivisionName() const;
    void setDivisionName(const string& divname);

    Division& operator=(const Division& other);
};

