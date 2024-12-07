#include <iostream>
#include <vector>
#include <string>
#include <optional>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date(int day, int month, int year) {
        setDate(day, month, year);
    }

    Date(const Date& date) {
        setDate(date.getDay(), date.getMonth(), date.getYear());
    }

    Date(const string& date) {
        parseFromString(date);
    }

    void setDate(int day, int month, int year) {
        if (!(day >= 1 && day <= 31)) throw out_of_range("Day not within range.");
        if (!(month >= 1 && month <= 12)) throw out_of_range("Month not within range.");
        if (!(year >= 1970)) throw out_of_range("Year not within range.");
        setYear(year);
        setMonth(month);
        setDay(day);
    }

    string getFormattedDate() const {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

    void setDay(int day) {
        if (day >= 1 && day <= 31) {
            this->day = day;
        }
    }

    void setMonth(int month) {
        if (month >= 1 && month <= 12) {
            this->month = month;
        }
    }

    void setYear(int year) {
        if (year >= 1970) {
            this->year = year;
        }
    }

    void parseFromString(const string& date) {
        int index = 0, d = 0, m = 0, y = 0;

        while (index < date.size() && date[index] != '/') {
            d = d * 10 + (date[index] - '0');
            index++;
        }
        index++;
        while (index < date.size() && date[index] != '/') {
            m = m * 10 + (date[index] - '0');
            index++;
        }
        index++;
        while (index < date.size()) {
            y = y * 10 + (date[index] - '0');
            index++;
        }

        if (d == 0 || m == 0 || y == 0) throw invalid_argument("Date not in correct format D/M/Y");
        setDate(d, m, y);
    }
};

class People {
private:
    string name;
    string SSNum;
    int age;

public:
    People() : name(""), SSNum(""), age(0) {}

    People(const string& name, const string& SSNum, int age) {
        setName(name);
        setSSNum(SSNum);
        setAge(age);
    }

    string getName() const { return name; }
    string getSSNum() const { return SSNum; }
    int getAge() const { return age; }

    void setName(const string& name) { this->name = name; }
    void setSSNum(const string& SSNum) { this->SSNum = SSNum; }
    void setAge(int age) {
        if (age >= 0) this->age = age;
    }
};

class Spouse : public People {
private:
    Date anniversaryDate;

public:
    Spouse() : anniversaryDate(1, 1, 1970) {}

    Spouse(const string& name, const string& SSNum, int age, const Date& anniversaryDate)
        : People(name, SSNum, age), anniversaryDate(anniversaryDate) {}

    Spouse(const Spouse& spouse)
        : People(spouse.getName(), spouse.getSSNum(), spouse.getAge()),
          anniversaryDate(spouse.anniversaryDate) {}

    void setAnniversaryDate(const Date& anniversaryDate) {
        this->anniversaryDate = anniversaryDate;
    }

    string getAnniversaryDate() const {
        return anniversaryDate.getFormattedDate();
    }

    Spouse operator=(const Spouse& other) {
        setName(other.getName());
        setAge(other.getAge());
        setSSNum(other.getSSNum());
        setAnniversaryDate(other.anniversaryDate);
        return *this;
    }
};

class Child : public People {
private:
    string favtoy;

public:
    Child() : favtoy("") {}

    Child(const string& name, const string& SSNum, int age, const string& favtoy)
        : People(name, SSNum, age), favtoy(favtoy) {}

    Child(const Child& child)
        : People(child.getName(), child.getSSNum(), child.getAge()),
          favtoy(child.favtoy) {}

    string getFavoriteToy() const { return favtoy; }

    void setFavoriteToy(const string& favtoy) { this->favtoy = favtoy; }

    Child operator=(const Child& other) {
        setName(other.getName());
        setAge(other.getAge());
        setSSNum(other.getSSNum());
        setFavoriteToy(other.favtoy);
        return *this;
    }
};

class Division {
private:
    string divname;

public:
    Division(const string& divname) : divname(divname) {}

    Division(const Division& division) : divname(division.divname) {}

    string getDivisionName() const { return divname; }

    void setDivisionName(const string& divname) { this->divname = divname; }

    Division operator=(const Division& other) {
        setDivisionName(other.divname);
        return *this;
    }
};

class JobDescription {
private:
    string description;

public:
    JobDescription(const string& description) : description(description) {}

    JobDescription(const JobDescription& jobDescription) : description(jobDescription.description) {}

    string getDescription() const { return description; }

    void setDescription(const string& description) { this->description = description; }

    JobDescription operator=(const JobDescription& other) {
        setDescription(other.description);
        return *this;
    }
};

class Employee : public People {
private:
    string companyID;
    string title;
    Date startDate;
    Division division;
    vector<JobDescription> jobDesc;
    optional<Spouse> spouse;
    vector<Child> children;

public:
    Employee(const string& name, const string& SSNum, int age,
             const string& companyID, const string& title, const Date& startDate,
             const Division& division, const vector<JobDescription>& jobDesc,
             optional<const Spouse> spouse, const vector<Child>& children = {})
        : People(name, SSNum, age),
          companyID(companyID), title(title), startDate(startDate),
          division(division), spouse(spouse) {
        if (jobDesc.empty()) throw invalid_argument("At least 1 Job Description required.");
        this->jobDesc = jobDesc;
        this->children = children;
    }

    string getCompanyID() const { return companyID; }
    string getTitle() const { return title; }
    string getStartDate() const { return startDate.getFormattedDate(); }

    void setCompanyID(const string& companyID) { this->companyID = companyID; }
    void setTitle(const string& title) { this->title = title; }
    void setStartDate(const Date& startDate) { this->startDate = startDate; }

    void setSpouse(const Spouse& spouse) {
        this->spouse = spouse;
    }

    void deleteSpouse() {
        this->spouse.reset();
    }

    optional<Spouse> getSpouse() const {
        return spouse;
    }

    void addChild(const Child& child) {
        children.push_back(child);
    }

    void addJobDescription(const JobDescription& jobDescription) {
        jobDesc.push_back(jobDescription);
    }

    void display() {
        cout << "Name: " << getName() << endl;
        cout << "SSN: " << getSSNum() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Company ID: " << getCompanyID() << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Start Date: " << getStartDate() << endl;
        cout << "Division: " << division.getDivisionName() << endl;

        cout << "Job Descriptions:" << endl;
        for (int i = 0; i < jobDesc.size(); i++) {
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
            for (int i = 0; i < children.size(); i++) {
                cout << "\t" << i + 1 << ". " << endl;
                cout << "\tName: " << children[i].getName() << endl;
                cout << "\tSSN: " << children[i].getSSNum() << endl;
                cout << "\tAge: " << children[i].getAge() << endl;
                cout << "\tFavorite Toy: " << children[i].getFavoriteToy() << endl;
            }
        }
    }
};

int main() {
    Child h("Amy", "4321-4321-4321", 3, "Doll");

    Employee a(
        "Fred", "1234-1234-1234", 32, 
        "company1", "CEO", Date("2/2/2004"),
        Division("div1"),
        {JobDescription("The best CEO")},
        Spouse("Shella", "1212-1212-1212", 30, Date(1, 2, 2003)),
        {h}
    );

    a.display();

    return 0;
}

