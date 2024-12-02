
#include "Date.h"
#include <iostream>
#include "Person.h"
#include "Division.h"
#include "JobDescription.h"
#include "Employee.h"
#include "Spouse.h"
#include "Child.h"

int main() {
    
    Date employeeStartDate(2022, 1, 1);
    Date spouseAnniversary(2010, 5, 20);

    
    Person person;
    person.setName("John Doe");
    person.setSSNum("123-45-6789");
    person.setAge(30);
    
    Jobdescription jobDesc1;
    jobDesc1.setDescription("Software Engineer");
    Jobdescription jobDesc2;
    jobDesc2.setDescription("Senior Software Engineer");

    
    Division division;
    division.setDivisionName("Engineering");

    // Create an Employee with a specific Division
    Employee employee(division);
    employee.setCompanyID("EMP123");
    employee.setTitle("Software Engineer");
    employee.setStartDate(employeeStartDate);
    employee.addJobDescription(jobDesc1);
    employee.addJobDescription(jobDesc2);

    
    Spouse spouse;
    spouse.setName("Jane Doe");
    spouse.setSSNum("987-65-4321");
    spouse.setAge(28);
    spouse.setAnniversaryDate(spouseAnniversary);
    spouse.setEmployee(&employee);

    
    Child child;
    child.setName("Child Doe");
    child.setSSNum("111-22-3333");
    child.setAge(5);
    child.setFavouriteToy("Teddy Bear");
    child.setEmployee(&employee);

    
    cout << "Employee Information:" << endl;
    cout << "Name: " << employee.getName() << endl;
    cout << "Company ID: " << employee.getCompanyID() << endl;
    cout << "Title: " << employee.getTitle() << endl;
    cout << "Start Date: ";
    employee.getStartDate().display();
    cout << "Division: " << employee.getDivision()->getDivisionName() << endl;

    cout << "\nSpouse Information:" << endl;
    cout << "Name: " << spouse.getName() << endl;
    cout << "SSN: " << spouse.getSSNum() << endl;
    cout << "Age: " << spouse.getAge() << endl;
    cout << "Anniversary Date: ";
    spouse.getAnniversaryDate().display();
    cout << "Employee: " << spouse.getEmployee()->getName() << endl;

    cout << "\nChild Information:" << endl;
    cout << "Name: " << child.getName() << endl;
    cout << "SSN: " << child.getSSNum() << endl;
    cout << "Age: " << child.getAge() << endl;
    cout << "Favourite Toy: " << child.getFavouriteToy() << endl;
    cout << "Employee: " << child.getEmployee()->getName() << endl;

    return 0;
}
