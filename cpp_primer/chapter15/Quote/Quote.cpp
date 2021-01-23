#include "Quote.h"

void Quote::debug(std::ostream &os) const {
    os << "Book No: " << isbn() << ", price: " << price;
}