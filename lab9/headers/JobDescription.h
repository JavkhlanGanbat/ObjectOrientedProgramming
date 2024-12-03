#pragma once

#include <iostream>
#include <string>
using namespace std;
class Jobdescription {
private:
    string Description;

public:
    string getDescription() const;
    void setDescription(string Description);
};

