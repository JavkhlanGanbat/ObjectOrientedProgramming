// Spouse.cpp
#include "Spouse.h"

void Spouse::setAnniversaryDate(const Date& newAnniversaryDate) {
    anniversaryDate = newAnniversaryDate;
}

Date Spouse::getAnniversaryDate() const {
    return anniversaryDate;
}

void Spouse::setEmployee(Employee* newEmployee) {
    myEmployee = newEmployee;
}

Employee* Spouse::getEmployee() const {
    return myEmployee;
}
