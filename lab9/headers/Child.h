// Child.h
#ifndef CHILD_H
#define CHILD_H
#include <iostream>

#include "Person.h"
#include "Employee.h"
using namespace std;

class Child : public Person {
private:
    string favouriteToy;
    Employee* myEmployee;

public:
    void setFavouriteToy(string newFavouriteToy);
    string getFavouriteToy() const;
    void setEmployee(Employee* newEmployee);
    Employee* getEmployee() const;
};

#endif // CHILD_H
