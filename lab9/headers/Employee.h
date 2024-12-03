#pragma once 

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
    const Division* empDivision;  
    vector<Jobdescription> jobDescriptions;  

public:
    Employee(const Division& division);
    void setCompanyID(string companyID);
    string getCompanyID() const;
    void setTitle(string title);
    string getTitle() const;
    void setStartDate(const Date& startDate);
    Date getStartDate() const;
    void setSpouse(Spouse* mySpouse);
    Spouse* getSpouse() const;
    void setChildren(Child* myChildren);
    Child* getChildren() const;
    void setDivision(Division* empDivision);
    const Division* getDivision() const;
    void addJobDescription(const Jobdescription& jobDesc);
    const vector<Jobdescription>& getJobDescriptions() const;

    Employee();
};
