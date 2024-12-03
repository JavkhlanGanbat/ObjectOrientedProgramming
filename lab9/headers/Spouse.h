#pragma once

#include <iostream>
#include "Person.h"
#include "Date.h"

class Employee;

class Spouse : public Person {
private:
    Date anniversaryDate;
    Employee* myEmployee;

public:
    void setAnniversaryDate(const Date& abort);
    Date getAnniversaryDate() const;
    void setEmployee(Employee* myEmployee);
    Employee* getEmployee() const;
};
