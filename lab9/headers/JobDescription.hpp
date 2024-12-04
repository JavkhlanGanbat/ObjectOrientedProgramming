#pragma once

#include <string>
using namespace std;

class JobDescription {
private:
    string description;

public:
    JobDescription(const string& description);
    JobDescription(const JobDescription& jobDescription);

    string getDescription() const;
    void setDescription(const string& description);

    JobDescription& operator=(const JobDescription& other);
};

