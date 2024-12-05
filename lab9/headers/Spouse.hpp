#pragma once

#include "../headers/Person.hpp"
#include "Date.hpp"

class Spouse : public Person {
private:
    Date anniversaryDate;

public:
    Spouse();
    Spouse(const string& name, const string& SSNum, int age, const Date& anniversaryDate);
    Spouse(const Spouse& spouse);

    void setAnniversaryDate(const Date& anniversaryDate);
    string getAnniversaryDate() const;
};

