#include "Person.h"

std::istream &read(std::istream &is, Person &person) {
    is >> person.p_name >> person.p_address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person) {
    os << person.name() << " " << person.address() << std::endl;
    return os;
}