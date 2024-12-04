#include "../headers/Child.hpp"

Child::Child() : favtoy("") {}

Child::Child(const string& name, const string& SSNum, int age, const string& favtoy)
    : Person(name, SSNum, age), favtoy(favtoy) {}

Child::Child(const Child& child)
    : Person(child.getName(), child.getSSNum(), child.getAge()),
      favtoy(child.favtoy) {}

string Child::getFavoriteToy() const { return favtoy; }

void Child::setFavoriteToy(const string& favtoy) { this->favtoy = favtoy; }

Child& Child::operator=(const Child& other) {
    setName(other.getName());
    setAge(other.getAge());
    setSSNum(other.getSSNum());
    setFavoriteToy(other.favtoy);
    return *this;
}
