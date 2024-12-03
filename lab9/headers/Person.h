#pragma once 

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

    void setName(string name);
    void setSSNum(string SSNum);
    void setAge(int age);
};
