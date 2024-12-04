#pragma once

#include "../headers/Person.hpp"
#include <string>
using namespace std;

class Child : public Person {
private:
    string favtoy;

public:
    Child();
    Child(const string& name, const string& SSNum, int age, const string& favtoy);
    Child(const Child& child);

    string getFavoriteToy() const;
    void setFavoriteToy(const string& favtoy);

    Child& operator=(const Child& other);
};
