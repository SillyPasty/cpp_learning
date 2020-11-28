#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>
#endif
using std::string;
class Person {
    friend std::istream &read(std::istream &, Person &);
    friend std::ostream &print(std::ostream &, const Person &);

public:
    Person() = default;
    Person(string &pn, string &pa) : p_name(pn), p_address(pa){};
    Person(std::istream &is) {
        read(is, *this);
    }

    string name() const {
        return p_name;
    }
    string address() const {
        return p_address;
    }

private:
    string p_name;
    string p_address;
};

std::istream &read(std::istream &, Person &);
std::ostream &print(std::ostream &, const Person &);
