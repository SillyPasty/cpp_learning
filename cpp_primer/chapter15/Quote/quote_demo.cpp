#include <iostream>

#include "Bulk_quote.h"
#include "Quote.h"
// double print_total(std::ostream, const Quote &, size_t);

int main() {
    std::cout << "starting" << std::endl;
    std::string name("QAQ");
    // Quote quote(name, 50.0);
    // Bulk_quote bulk_quote("QAQ", 50, 3, 0.2);
    // quote.debug(std::cout);
    // std::cout << std::endl;
    // bulk_quote.debug(std::cout);
    std::cout << "exiting" << std::endl;
}

// double print_total(std::ostream &os, const Quote &item, size_t n) {
//     double ret = item.net_price(n);
//     os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
//        << std::endl;
//     return ret;
// }