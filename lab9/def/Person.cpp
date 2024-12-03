// Person.cpp
#include "../headers/Person.h"


string Person::getName() const {
    return Name;
}

string Person::getSSNum() const {
    return SSNum;
}

int Person::getAge() const {
    return age;
}

void Person::setName(string Name) {
    this->Name = Name;
}

void Person::setSSNum(string SSNum) {
    this->SSNum = SSNum;
}

void Person::setAge(int age) {
    this->age = age;
}
