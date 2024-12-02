// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <vector>
#include "Date.h"
#include "Person.h"
#include "Division.h"
#include "JobDescription.h"
using namespace std;

class Spouse;
class Child;

class Employee : public Person {
private:
    string companyID;
    string title;
    Date startDate;
    Spouse* mySpouse;
    Child* myChildren;
    Division* empDivision;  
    vector<Jobdescription> jobDescriptions;  

public:
    Employee(const Division& division);
    void setCompanyID(string newCompanyID);
    string getCompanyID() const;
    void setTitle(string newTitle);
    string getTitle() const;
    void setStartDate(const Date& newStartDate);
    Date getStartDate() const;
    void setSpouse(Spouse* newSpouse);
    Spouse* getSpouse() const;
    void setChildren(Child* newChildren);
    Child* getChildren() const;
    void setDivision(Division* empDivision);
    Division* getDivision() const;
    void addJobDescription(const Jobdescription& jobDesc);
    const vector<Jobdescription>& getJobDescriptions() const;

    Employee();
};

#endif // EMPLOYEE_H
