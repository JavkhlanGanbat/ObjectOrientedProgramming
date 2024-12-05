#include "../headers/Spouse.hpp"

Spouse::Spouse() : anniversaryDate(1, 1, 1970) {}

Spouse::Spouse(const string& name, const string& SSNum, int age, const Date& anniversaryDate)
    : Person(name, SSNum, age), anniversaryDate(anniversaryDate) {}

Spouse::Spouse(const Spouse& spouse)
    : Person(spouse.getName(), spouse.getSSNum(), spouse.getAge()),
      anniversaryDate(spouse.anniversaryDate) {}

void Spouse::setAnniversaryDate(const Date& anniversaryDate) {
    this->anniversaryDate = anniversaryDate;
}

string Spouse::getAnniversaryDate() const {
    return anniversaryDate.getFormattedDate();
}
