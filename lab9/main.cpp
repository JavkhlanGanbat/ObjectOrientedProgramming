#include "headers/Employee.hpp"
#include <iostream>
using namespace std;

int main() {
    Date startDate(1, 1, 2020);
    Division division("Software development");
    JobDescription jobDesc1("Software engineer");
    JobDescription jobDesc2("Project manager");
    vector<JobDescription> jobDescriptions = {jobDesc1, jobDesc2};
    Spouse spouse("Jane Smith", "123-45-6789", 30, Date(1, 1, 2010));
    Child child1("Alice", "987-65-4321", 5, "Lego");
    Child child2("Kyle", "4322-4322-4322", 4, "Lego");
    vector<Child> children = {child1, child2};

    Employee employee("John Smith", "123-45-6789", 35, "001", "Senior",
                      startDate, division, jobDescriptions, spouse, children);

    cout << "Initial Employee Details:\n";
    employee.display();

    employee.setCompanyID("002");
    employee.setTitle("Lead dev");
    employee.setStartDate(Date(2, 2, 2022));
    employee.setSpouse(Spouse("Emily Smith", "456-78-9123", 28, Date(5, 5, 2015)));

    employee.addJobDescription(JobDescription("Technical lead"));
    employee.addChild(Child("Emma", "555-55-5555", 3, "Barbie"));

    employee.display();

    employee.deleteSpouse();
    employee.deleteJobDescription(1);
    employee.deleteChild(1);

    employee.display();

    return 0;
}
