#include "classDef.h"

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
                // Objectiig nereer erembeleh
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
                    for (i = 0; i < numOfEmployees; i++) {
                    emps[i]->print();
                    cout << "\n";
                }
                break;
            }
            case 4: {
                // Pointeriig haygaar ni erembeleh
                for (i = 0; i < numOfEmployees - 1; i++) {
                    for (int j = i + 1; j < numOfEmployees; j++) {
                        if (emps[i] > emps[j]) {
                            Employee* temp = emps[i];
                            emps[i] = emps[j];
                            emps[j] = temp;
                        }
                    }
                }
                cout << "Haygaar erembellee." << endl;
                for (i = 0; i < numOfEmployees; i++) {
                    cout << "\nAddress: " << emps[i] << endl;
                    emps[i]->print();
    }
    break;
            }
            case 5: {
                // Tsalingaar erembeleh
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
                // Erembelsen objectuudiig heveleh functs
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
