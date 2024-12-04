#include "../headers/JobDescription.hpp"

JobDescription::JobDescription(const string& description) : description(description) {}

JobDescription::JobDescription(const JobDescription& jobDescription) 
    : description(jobDescription.description) {}

string JobDescription::getDescription() const { return description; }

void JobDescription::setDescription(const string& description) { this->description = description; }

JobDescription& JobDescription::operator=(const JobDescription& other) {
    if (this != &other) { setDescription(other.description); }
    return *this;
}
