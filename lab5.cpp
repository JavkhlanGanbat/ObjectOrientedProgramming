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

    // Parameterized constructor
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

// Compare functions for sorting
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

int main() {
    Employee* emps[100];
    int numOfEmployees = 0, action = 1, id, i, h;
    char tempName[100], tempPos[100];

    while (action != 0) {
        cout << "\n=== Employee Class ===" << endl;
        cout << "1. Ajilchin nemeh" << endl;
        cout << "2. Medeelel hevleh" << endl;
        cout << "3. Nereer erembeleh" << endl;
        cout << "4. Haygaar erembeleh" << endl;
        cout << "5. Tsalingaar erembeleh" << endl;
        cout << "6. Ajilchnii medeelel zasvarlah" << endl;
        cout << "7. Buh ajilchnii medeelel" << endl;
        cout << "0. Garah" << endl;
        cout << "Songolt oruulna uu (0-7): "; 
        cin >> action;

        switch (action) {
            case 1: {
                cout << "ID: "; 
                cin >> id;
                
                bool idExists = false;
                for (i = 0; i < numOfEmployees; i++) {
                    if (emps[i]->getID() == id) {
                        idExists = true;
                        cout << "Ene ID-tai ajilchin burtgeltei baina!" << endl;
                        break;
                    }
                }
                
                if (!idExists) {
                    cout << "Ner: "; cin >> tempName;
                    cout << "Alban tushaal: "; cin >> tempPos;
                    cout << "Ajillasan tsag: "; cin >> h;
                    
                    emps[numOfEmployees] = new Employee(id, tempName, tempPos, h);
                    numOfEmployees++;
                    cout << "Ajilchin amjilttai burtgegdlee." << endl;
                }
                break;
            }
            case 2: {
                cout << "Ajilchnii ID: "; 
                cin >> id;
                bool found = false;
                for (i = 0; i < numOfEmployees; i++) {
                    if (emps[i]->getID() == id) {
                        emps[i]->print();
                        found = true;
                        break;
                    }
                }
                if (!found) 
                    cout << "Iim ID-tai ajilchin oldsongui." << endl;
                break;
            }
            case 3: {
                // Sort by name
                for (i = 0; i < numOfEmployees - 1; i++) {
                    for (int j = i + 1; j < numOfEmployees; j++) {
                        if (cmpEmpByName(*emps[i], *emps[j]) > 0) {
                            Employee* temp = emps[i];
                            emps[i] = emps[j];
                            emps[j] = temp;
                        }
                    }
                }
                cout << "Nereer erembellee." << endl;
                break;
            }
            case 4: {
                // Sort pointers by name
                for (i = 0; i < numOfEmployees - 1; i++) {
                    for (int j = i + 1; j < numOfEmployees; j++) {
                        if (strcmp(emps[i]->getName(), emps[j]->getName()) > 0) {
                            Employee* temp = emps[i];
                            emps[i] = emps[j];
                            emps[j] = temp;
                        }
                    }
                }
                cout << "Haygaar erembellee." << endl;
                break;
            }
            case 5: {
                // Sort by salary (descending order)
                for (i = 0; i < numOfEmployees - 1; i++) {
                    for (int j = i + 1; j < numOfEmployees; j++) {
                        if (cmpEmpBySalary(*emps[i], *emps[j]) > 0) {
                            Employee* temp = emps[i];
                            emps[i] = emps[j];
                            emps[j] = temp;
                        }
                    }
                }
                cout << "Tsalingaar erembellee." << endl;
                // Print sorted results
                for (i = 0; i < numOfEmployees; i++) {
                    cout << "\nRank #" << (i + 1) << endl;
                    emps[i]->print();
                }
                break;
            }
            case 6: {
                cout << "Zasvarlah ajilchnii ID: ";
                cin >> id;
                bool found = false;
                for (i = 0; i < numOfEmployees; i++) {
                    if (emps[i]->getID() == id) {
                        found = true;
                        int choice;
                        cout << "\nOdoogiin medeelel:" << endl;
                        emps[i]->print();
                        cout << "\nYug zasvarlah ve?" << endl;
                        cout << "1. Ner" << endl;
                        cout << "2. Alban tushaal" << endl;
                        cout << "3. Ajillasan tsag" << endl;
                        cout << "0. Butsah" << endl;
                        cout << "Songolt: ";
                        cin >> choice;
                        
                        switch(choice) {
                            case 1:
                                cout << "Shine ner: ";
                                cin >> tempName;
                                emps[i]->setName(tempName);
                                break;
                            case 2:
                                cout << "Shine alban tushaal: ";
                                cin >> tempPos;
                                emps[i]->setPosition(tempPos);
                                break;
                            case 3:
                                cout << "Shine ajillasan tsag: ";
                                cin >> h;
                                emps[i]->setWorkHours(h);
                                break;
                            case 0:
                                break;
                            default:
                                cout << "Buruu songolt!" << endl;
                        }
                        if (choice >= 1 && choice <= 3) {
                            cout << "Medeelel amjilttai zasvarlagdlaa!" << endl;
                        }
                        break;
                    }
                }
                if (!found)
                    cout << "Iim ID-tai ajilchin oldsongui." << endl;
                break;
            }
            case 7: {
                if (numOfEmployees == 0) {
                    cout << "Burtgeltei ajilchin baihgui baina." << endl;
                } else {
                    for (i = 0; i < numOfEmployees; i++) {
                        cout << "\nAjilchin #" << (i + 1) << endl;
                        emps[i]->print();
                    }
                }
                break;
            }
            case 0: {
                for (i = 0; i < numOfEmployees; i++) {
                    delete emps[i];
                }
                cout << "Program duuslaa." << endl;
                break;
            }
            default:
                cout << "Buruu songolt!" << endl;
                break;
        }
    }
    return 0;
}
