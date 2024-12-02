// Person.cpp
#include "Person.h"


string Person::getName() const {
    return Name;
}

string Person::getSSNum() const {
    return SSNum;
}

int Person::getAge() const {
    return age;
}

void Person::setName(string newName) {
    Name = newName;
}

void Person::setSSNum(string newSSNum) {
    SSNum = newSSNum;
}

void Person::setAge(int newAge) {
    age = newAge;
}
