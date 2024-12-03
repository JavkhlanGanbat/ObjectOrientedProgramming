#include "../headers/Employee.h"

Employee::Employee(const Division& division) {
    empDivision = &division;     
}

void Employee::setCompanyID(string companyID) {
    this->companyID = companyID;
}

string Employee::getCompanyID() const {
    return companyID;
}

void Employee::setTitle(string title) {
    this->title = title;
}

string Employee::getTitle() const {
    return title;
}

void Employee::setStartDate(const Date& startDate) {
    this->startDate = startDate;
}

Date Employee::getStartDate() const {
    return startDate;
}

void Employee::setSpouse(Spouse* mySpouse) {
    this->mySpouse = mySpouse;
}

Spouse* Employee::getSpouse() const {
    return mySpouse;
}

void Employee::setChildren(Child* myChildren) {
    this->myChildren = myChildren;
}

Child* Employee::getChildren() const {
    return myChildren;
}

void Employee::setDivision(Division* empDivision) {
    this->empDivision = empDivision;
}

const Division* Employee::getDivision() const {
    return empDivision;
}

void Employee::addJobDescription(const Jobdescription& jobDesc) {
    jobDescriptions.push_back(jobDesc);
}

const vector<Jobdescription>& Employee::getJobDescriptions() const {
    return jobDescriptions;
}

Employee::Employee() : startDate() {}
