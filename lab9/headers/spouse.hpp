#include"../headers/date.hpp"
#include"person.hpp"

class Spouse : public Person {
    protected:
        Date anniversaryDate;

    public: 
        Date getAnniversaryDate();
};