#include "../headers/Employee.hpp"

/* Employee class-iin baiguulagch 
jobDesc vector hooson esehiig shalgaj, hooson bol aldaa zaana
jobDesc, children 2-g baiguulagch dotor 
 */
Employee::Employee(const string& name, const string& SSNum, int age,
                   const string& companyID, const string& title, const Date& startDate,
                   const Division& division, const vector<JobDescription>& jobDesc,
                   optional<const Spouse> spouse, const vector<Child>& children)
                    : Person(name, SSNum, age), companyID(companyID), title(title),
                    startDate(startDate), division(division), spouse(spouse), children(children){
    if (jobDesc.empty()) throw invalid_argument("At least 1 job desc required.");
    this->jobDesc = jobDesc;
}

//getter, setter
string Employee::getCompanyID() const { return companyID; }
string Employee::getTitle() const { return title; }
string Employee::getStartDate() const { return startDate.getFormattedDate(); }
optional<Spouse> Employee::getSpouse() const { return spouse; }

void Employee::setCompanyID(const string& companyID) { this->companyID = companyID; }
void Employee::setTitle(const string& title) { this->title = title; }
void Employee::setStartDate(const Date& startDate) { this->startDate = startDate; }
void Employee::setSpouse(const Spouse& spouse) { this->spouse = spouse; }

// Spouse ustgah uyd "spouse" nertei optional objectiin "reset" method-g duudaj hooslono
void Employee::deleteSpouse() { this->spouse.reset(); }

// child objectiig vector-d "push_back" argaar nemne
void Employee::addChild(const Child& child) {
    children.push_back(child);
}

// i-r index deer bga child objectiig ustgana
void Employee::deleteChild(int i) {
    if (i >= 0 && i < (int)(children.size() + 1)) {
        children.erase(children.begin() + i - 1);
    } else {
        throw out_of_range("Index out of range for children.");
    }
}

// jobDesc vector-d "push_back" argaar nemne
void Employee::addJobDescription(const JobDescription& jobDescription) {
    jobDesc.push_back(jobDescription);
}
// i-r index deer bga jobDesc objectiig ustgana
void Employee::deleteJobDescription(int i) {
    if (jobDesc.size() > 1) {
        if (i >= 0 && i < (int)(jobDesc.size())) {
            jobDesc.erase(jobDesc.begin() + i - 1);
        } else {
            throw out_of_range("Index out of range for job descriptions.");
        }
    } else {
        throw logic_error("Employee must have at least one Job Description.");
    }
}

// Employee objectiin buh medeelliig hevleh functs
void Employee::display() const {
    cout << "\n" << "Name: " << getName() << "\n";
    cout << "SSN: " << getSSNum() << "\n";
    cout << "Age: " << getAge() << "\n";
    cout << "Company ID: " << getCompanyID() << "\n";
    cout << "Title: " << getTitle() << "\n";
    cout << "Start Date: " << getStartDate() << "\n";
    cout << "Division: " << division.getDivisionName() << "\n";

    cout << "Job Descriptions:" << "\n";
    for (size_t i = 0; i < jobDesc.size(); i++) {
        cout << "\t" << i + 1 << ". " << jobDesc[i].getDescription() << "\n";
    }

    if (spouse.has_value()) { 
        cout << "Spouse:" << "\n"; 
        cout << "\tName: " << spouse->getName() << "\n"; 
        cout << "\tSSN: " << spouse->getSSNum() << "\n"; 
        cout << "\tAge: " << spouse->getAge() << "\n"; 
        cout << "\tAnniversary Date: " << spouse->getAnniversaryDate() << "\n"; 
    }
        
    if (!children.empty()) {
        cout << "Children:" << "\n";
        for (size_t i = 0; i < children.size(); i++) {
            cout << "\t" << i + 1 << ". " << "\n";
            cout << "\tName: " << children[i].getName() << "\n";
            cout << "\tSSN: " << children[i].getSSNum() << "\n";
            cout << "\tAge: " << children[i].getAge() << "\n";
            cout << "\tFavorite Toy: " << children[i].getFavoriteToy() << "\n\n";
        }
    }
}
