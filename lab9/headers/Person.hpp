#pragma once

#include <string>
using namespace std;

class People {
private:
    string name;
    string SSNum;
    int age;

public:
    People();
    People(const string& name, const string& SSNum, int age);

    string getName() const;
    string getSSNum() const;
    int getAge() const;

    void setName(const string& name);
    void setSSNum(const string& SSNum);
    void setAge(int age);
};

