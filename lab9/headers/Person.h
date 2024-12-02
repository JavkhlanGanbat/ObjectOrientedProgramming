// Person.h
#ifndef PERSON_H
#define PERSON_H
using namespace std;

#include <string>
#include <iostream>
class Person {
protected:
    string Name;
    string SSNum;
    int age;

public:
    string getName() const;
    string getSSNum() const;
    int getAge() const;

    void setName(string newName);
    void setSSNum(string newSSNum);
    void setAge(int newAge);
};

#endif // PERSON_H
