#include "headers/Date.hpp"
#include "headers/Person.hpp"
#include "headers/Spouse.hpp"
#include "headers/Child.hpp"
#include "headers/Division.hpp"
#include "headers/JobDescription.hpp"
#include "headers/Employee.hpp"

#include <iostream>
using namespace std;

int main() {
    Date startDate(1, 1, 2020);
    Division division("Software Development");
    JobDescription jobDesc("Software Engineer");
    vector<JobDescription> jobDescriptions = {jobDesc};
    Spouse spouse("Jane Doe", "123-45-6789", 30, Date(1, 1, 2010));
    Child child("Alice", "987-65-4321", 5, "Lego Set");
    vector<Child> children = {child};

    Employee employee("John Doe", "123-45-6789", 35, "001", "Team Lead",
                      startDate, division, jobDescriptions, spouse, children);

    employee.display();

    return 0;
}
