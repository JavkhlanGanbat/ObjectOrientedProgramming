#include "../headers/Person.hpp"

People::People() : name(""), SSNum(""), age(0) {}

People::People(const string& name, const string& SSNum, int age) {
    setName(name);
    setSSNum(SSNum);
    setAge(age);
}

string People::getName() const { return name; }

string People::getSSNum() const { return SSNum; }

int People::getAge() const { return age; }

void People::setName(const string& name) { this->name = name; }

void People::setSSNum(const string& SSNum) { this->SSNum = SSNum; }

void People::setAge(int age) {
    if (age >= 0) this->age = age;
}
