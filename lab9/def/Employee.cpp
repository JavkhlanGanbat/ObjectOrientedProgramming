
#include "Employee.h"


Employee::Employee(const Division& division) {
    empDivision = division;     
}

void Employee::setCompanyID(string newCompanyID) {
    companyID = newCompanyID;
}

string Employee::getCompanyID() const {
    return companyID;
}

void Employee::setTitle(string newTitle) {
    title = newTitle;
}

string Employee::getTitle() const {
    return title;
}

void Employee::setStartDate(const Date& newStartDate) {
    startDate = newStartDate;
}

Date Employee::getStartDate() const {
    return startDate;
}

void Employee::setSpouse(Spouse* newSpouse) {
    mySpouse = newSpouse;
}

Spouse* Employee::getSpouse() const {
    return mySpouse;
}

void Employee::setChildren(Child* newChildren) {
    myChildren = newChildren;
}

Child* Employee::getChildren() const {
    return myChildren;
}

void Employee::setDivision(Division* empDivision) {
    this->empDivision = empDivision;
}

Division* Employee::getDivision() const {
    return empDivision;
}

void Employee::addJobDescription(const Jobdescription& jobDesc) {
    jobDescriptions.push_back(jobDesc);
}

const vector<Jobdescription>& Employee::getJobDescriptions() const {
    return jobDescriptions;
}

Employee::Employee() : startDate() {}
