#ifndef JOBDESCRIPTION_H
#define JOBDESCRIPTION_H
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

#endif // JOBDESCRIPTION_H
