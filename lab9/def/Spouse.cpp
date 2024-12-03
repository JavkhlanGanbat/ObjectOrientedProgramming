// Spouse.cpp
#include "../headers/Spouse.h"

void Spouse::setAnniversaryDate(const Date& anniversaryDate) {
    this->anniversaryDate = anniversaryDate;
}

Date Spouse::getAnniversaryDate() const {
    return anniversaryDate;
}

void Spouse::setEmployee(Employee* myEmployee) {
    this->myEmployee = myEmployee;
}

Employee* Spouse::getEmployee() const {
    return myEmployee;
}
