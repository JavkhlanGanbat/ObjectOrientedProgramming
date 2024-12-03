#pragma once

#include <iostream>

#include "Person.h"
#include "Employee.h"
using namespace std;

class Child : public Person {
private:
    string favouriteToy;
    Employee* myEmployee;

public:
    void setFavouriteToy(string favouriteToy);
    string getFavouriteToy() const;
    void setEmployee(Employee* myEmployee);
    Employee* getEmployee() const;
};
