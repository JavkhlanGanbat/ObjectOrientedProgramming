#pragma once

#include "../headers/Person.hpp"
#include <string>
using namespace std;

class Child : public Person {
private:
    string favtoy;

public:
    // garaanii baiguulagch
    Child();
    // parametrtei baiguulagch
    Child(const string& name, const string& SSNum, int age, const string& favtoy); 
    // huulagch baiguulagch
    Child(const Child& child); 

    //getter, setter
    string getFavoriteToy() const;
    void setFavoriteToy(const string& favtoy);
};
