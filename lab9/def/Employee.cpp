#include "../headers/Employee.hpp"

// Constructor
Employee::Employee(const string& name, const string& SSNum, int age,
                   const string& companyID, const string& title, const Date& startDate,
                   const Division& division, const vector<JobDescription>& jobDesc,
                   optional<const Spouse> spouse, const vector<Child>& children)
    : People(name, SSNum, age),
      companyID(companyID), title(title), startDate(startDate),
      division(division), spouse(spouse) {
    if (jobDesc.empty()) throw invalid_argument("At least 1 job desc required.");
    this->jobDesc = jobDesc;
    this->children = children;
}

// Getters
string Employee::getCompanyID() const { return companyID; }
string Employee::getTitle() const { return title; }
string Employee::getStartDate() const { return startDate.getFormattedDate(); }
optional<Spouse> Employee::getSpouse() const { return spouse; }

// Setters
void Employee::setCompanyID(const string& companyID) { this->companyID = companyID; }
void Employee::setTitle(const string& title) { this->title = title; }
void Employee::setStartDate(const Date& startDate) { this->startDate = startDate; }
void Employee::setSpouse(const Spouse& spouse) { this->spouse = spouse; }

// Delete spouse
void Employee::deleteSpouse() { this->spouse.reset(); }

// Add child and job description
void Employee::addChild(const Child& child) {
    children.push_back(child);
}

void Employee::addJobDescription(const JobDescription& jobDescription) {
    jobDesc.push_back(jobDescription);
}

// Display information
void Employee::display() const {
    cout << "Name: " << getName() << endl;
    cout << "SSN: " << getSSNum() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Company ID: " << getCompanyID() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Start Date: " << getStartDate() << endl;
    cout << "Division: " << division.getDivisionName() << endl;

    cout << "Job Descriptions:" << endl;
    for (size_t i = 0; i < jobDesc.size(); i++) {
        cout << "\t" << i + 1 << ". " << jobDesc[i].getDescription() << endl;
    }

    if (spouse.has_value()) { 
        cout << "Spouse:" << endl; 
        cout << "\tName: " << spouse->getName() << endl; 
        cout << "\tSSN: " << spouse->getSSNum() << endl; 
        cout << "\tAge: " << spouse->getAge() << endl; 
        cout << "\tAnniversary Date: " << spouse->getAnniversaryDate() << endl; 
        }
        
    if (!children.empty()) {
        cout << "Children:" << endl;
        for (size_t i = 0; i < children.size(); i++) {
            cout << "\t" << i + 1 << ". " << endl;
            cout << "\tName: " << children[i].getName() << endl;
            cout << "\tSSN: " << children[i].getSSNum() << endl;
            cout << "\tAge: " << children[i].getAge() << endl;
            cout << "\tFavorite Toy: " << children[i].getFavoriteToy() << endl;
        }
    }
}