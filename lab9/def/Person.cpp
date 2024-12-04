#include "../headers/Person.hpp"

Person::Person() : name(""), SSNum(""), age(0) {}

Person::Person(const string& name, const string& SSNum, int age) {
    setName(name);
    setSSNum(SSNum);
    setAge(age);
}

string Person::getName() const { return name; }

string Person::getSSNum() const { return SSNum; }

int Person::getAge() const { return age; }

void Person::setName(const string& name) { this->name = name; }

void Person::setSSNum(const string& SSNum) { this->SSNum = SSNum; }

void Person::setAge(int age) {
    if (age >= 0) this->age = age;
}
