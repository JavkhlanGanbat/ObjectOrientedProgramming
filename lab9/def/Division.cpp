#include "../headers/Division.hpp"

Division::Division(const string& divname) : divname(divname) {}

Division::Division(const Division& division) : divname(division.divname) {}

string Division::getDivisionName() const { return divname; }

void Division::setDivisionName(const string& divname) { this->divname = divname; }

