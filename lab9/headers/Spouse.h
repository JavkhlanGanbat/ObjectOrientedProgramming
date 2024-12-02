// Spouse.h
#ifndef SPOUSE_H
#define SPOUSE_H
#include <iostream>
#include "Person.h"
#include "Date.h"

class Employee;

class Spouse : public Person {
private:
    Date anniversaryDate;
    Employee* myEmployee;

public:
    void setAnniversaryDate(const Date& newAnniversaryDate);
    Date getAnniversaryDate() const;
    void setEmployee(Employee* newEmployee);
    Employee* getEmployee() const;
};

#endif // SPOUSE_H
