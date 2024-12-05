#include "../headers/Child.hpp"

Child::Child() : favtoy("") {}

Child::Child(const string& name, const string& SSNum, int age, const string& favtoy)
    : Person(name, SSNum, age), favtoy(favtoy) {}

Child::Child(const Child& child)
    : Person(child.getName(), child.getSSNum(), child.getAge()),
      favtoy(child.favtoy) {}

string Child::getFavoriteToy() const { return favtoy; }

void Child::setFavoriteToy(const string& favtoy) { this->favtoy = favtoy; }
