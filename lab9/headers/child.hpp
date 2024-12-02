#pragma once
#include "person.hpp"

class Child : public Person{
    private:
        char* FavToy;
    public:
        void setFavToy(const char* FavToy);
        const char* getFavToy();
};