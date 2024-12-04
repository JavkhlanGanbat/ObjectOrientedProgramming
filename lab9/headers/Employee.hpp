#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include "Person.hpp"
#include "Date.hpp"
#include "Division.hpp"
#include "JobDescription.hpp"
#include "Spouse.hpp"
#include "Child.hpp"

using namespace std;

class Employee : public Person {
private:
    string companyID;
    string title;
    Date startDate;
    Division division;
    vector<JobDescription> jobDesc;
    optional<Spouse> spouse;
    vector<Child> children;

public:
    // Constructor
    Employee(const string& name, const string& SSNum, int age,
             const string& companyID, const string& title, const Date& startDate,
             const Division& division, const vector<JobDescription>& jobDesc,
             optional<const Spouse> spouse = nullopt, const vector<Child>& children = {});

    // Getters
    string getCompanyID() const;
    string getTitle() const;
    string getStartDate() const;
    optional<Spouse> getSpouse() const;

    // Setters
    void setCompanyID(const string& companyID);
    void setTitle(const string& title);
    void setStartDate(const Date& startDate);
    void setSpouse(const Spouse& spouse);

    // Delete spouse
    void deleteSpouse();

    // Add child and job description
    void addChild(const Child& child);
    void addJobDescription(const JobDescription& jobDescription);

    // Display information
    void display() const;
};
