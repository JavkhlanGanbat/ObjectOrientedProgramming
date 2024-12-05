#include "headers/Employee.hpp"
#include <iostream>
using namespace std;

int main() {
    // Employee object bolon tuunii shinj chanaruudiig uusgene
    Date startDate(1, 1, 2020);
    Division division("Software development");
    JobDescription jobDesc1("Software engineer");
    JobDescription jobDesc2("Project manager");
    vector<JobDescription> jobDescriptions = {jobDesc1, jobDesc2};
    Spouse spouse("Jane Smith", "123-45-6789", 30, Date(1, 1, 2010));
    Child child1("Alice", "987-65-4321", 5, "Lego");
    Child child2("Kyle", "4322-4322-4322", 4, "Car");
    vector<Child> children = {child1, child2};

    Employee employee("John Smith", "123-45-6789", 35, "001", "Senior",
                      startDate, division, jobDescriptions, spouse, children);
    // Ankh uusgesen Employee objectiig haruulah
    employee.display();

    /* CompanyID 001 -> 002, title Senior -> Lead dev, startDate 1/1/2020 -> 2/2/2022
    Spouse objectiig uur spouse objectoor solih, shine Child object nemeh
    */
    employee.setCompanyID("002");
    employee.setTitle("Lead dev");
    employee.setStartDate(Date(2, 2, 2022));
    employee.setSpouse(Spouse("Emily Smith", "456-78-9123", 28, Date(5, 5, 2015)));
    employee.addJobDescription(JobDescription("Technical lead"));
    
    Child child3;
    child3 = child2;
    child3.setName("Megan");
    employee.addChild(child3); 
    employee.display();

    employee.deleteSpouse();
    employee.deleteJobDescription(1);
    employee.deleteChild(3);

    employee.display();

    return 0;
}
