#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    int id;
    char* name;
    char* position;
    float workHours;

    float calcBossSalary() const{
        if (strcmp(position, "Boss") == 0)
            return 200;
        return 0;
    }

    float calcExtraSalary() const{
        if (workHours < 50) return 0;
        if (workHours < 100) return 50;
        if (workHours < 200) return 70;
        return 100;
    }

public:
    // Default constructor
    Employee() {
        id = 0;
        workHours = 0;
        name = new char[1];
        name[0] = '\0';
        position = new char[9];
        strcpy(position, "Employee");
    }

    // Parametertei constructor
    Employee(int i, const char* n, const char* pos, float hours) {
        id = i;
        workHours = hours;
        
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        
        position = new char[strlen(pos) + 1];
        strcpy(position, pos);
    }

    // Copy constructor
    Employee(const Employee& t) {
        id = t.id;
        workHours = t.workHours;
        
        name = new char[strlen(t.name) + 1];
        strcpy(name, t.name);
        
        position = new char[strlen(t.position) + 1];
        strcpy(position, t.position);
    }

    // Destructor
    ~Employee() {
        delete[] name;
        delete[] position;
    }

    // Copy assignment operator
    Employee& operator=(const Employee& t) {
        if (this != &t) {
            delete[] name;
            delete[] position;
            
            id = t.id;
            workHours = t.workHours;
            
            name = new char[strlen(t.name) + 1];
            strcpy(name, t.name);
            
            position = new char[strlen(t.position) + 1];
            strcpy(position, t.position);
        }
        return *this;
    }

    void getUserInput() {
        char tempName[100], tempPos[100];
        cout << "ID: "; cin >> id;
        cout << "Ner: "; cin >> tempName;
        cout << "Alban tushaal: "; cin >> tempPos;
        cout << "Niit ajillasan tsag: "; cin >> workHours;

        delete[] name;
        delete[] position;
        
        name = new char[strlen(tempName) + 1];
        strcpy(name, tempName);
        
        position = new char[strlen(tempPos) + 1];
        strcpy(position, tempPos);
    }

    float calcSalary() const {
        float baseSalary = 300;
        return baseSalary + calcBossSalary() + calcExtraSalary();
    }

    void print() const {
        cout << "ID: " << id << endl;
        cout << "Ner: " << name << endl;
        cout << "Alban tushaal: " << position << endl;
        cout << "Niit ajillasan tsag: " << workHours << endl;
        cout << "Tsalin: " << calcSalary() << endl;
    }

    bool addHoursWorked(float addedTime) {
        if (addedTime >= 0 && addedTime <= 24) {
            workHours += addedTime;
            return true;
        }
        return false;
    }

    int getID() const { return id; }
    const char* getName() const { return name; }
    const char* getPosition() const { return position; }
    float getHoursWorked() const { return workHours; }
    
    void setID(int i) { id = i; }
    void setName(const char* n) {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    void setPosition(const char* pos) {
        delete[] position;
        position = new char[strlen(pos) + 1];
        strcpy(position, pos);
    }
    void setWorkHours(float hours) { workHours = hours; }
};

// Haritsuulah functsuud
int cmpEmpByName(const Employee& A, const Employee& B) {
    return strcmp(A.getName(), B.getName());
}

int cmpEmpBySalary(const Employee& A, const Employee& B) {
    float salaryA = A.calcSalary();
    float salaryB = B.calcSalary();
    if (salaryA > salaryB) return -1;
    if (salaryA < salaryB) return 1;
    return 0;
}
