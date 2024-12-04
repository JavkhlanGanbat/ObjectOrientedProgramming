#include "../headers/Spouse.hpp"

Spouse::Spouse() : anniversaryDate(1, 1, 1970) {}

Spouse::Spouse(const string& name, const string& SSNum, int age, const Date& anniversaryDate)
    : People(name, SSNum, age), anniversaryDate(anniversaryDate) {}

Spouse::Spouse(const Spouse& spouse)
    : People(spouse.getName(), spouse.getSSNum(), spouse.getAge()),
      anniversaryDate(spouse.anniversaryDate) {}

void Spouse::setAnniversaryDate(const Date& anniversaryDate) {
    this->anniversaryDate = anniversaryDate;
}

string Spouse::getAnniversaryDate() const {
    return anniversaryDate.getFormattedDate();
}

Spouse Spouse::operator=(const Spouse& other) {
    setName(other.getName());
    setAge(other.getAge());
    setSSNum(other.getSSNum());
    setAnniversaryDate(other.anniversaryDate);
    return *this;
}
