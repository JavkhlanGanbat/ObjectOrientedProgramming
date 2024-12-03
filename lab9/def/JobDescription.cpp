// Jobdescription.cpp
#include "../headers/JobDescription.h"

string Jobdescription::getDescription() const {
    return Description;
}

void Jobdescription::setDescription(string Description) {
    this->Description = Description;
}
