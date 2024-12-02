// Child.cpp
#include "Child.h"
void Child::setFavouriteToy(string favouriteToy) {
    this->favouriteToy = favouriteToy;
}
string Child::getFavouriteToy() const {
    return favouriteToy;
}
void Child::setEmployee(Employee* myEmployee) {
    this->myEmployee = myEmployee;
}
Employee* Child::getEmployee() const {
    return myEmployee;
}
