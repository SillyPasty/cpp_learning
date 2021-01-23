#ifndef QUOTE_HPP
#define QUOTE_HPP
#include <iostream>
#include <string>
class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price)
        : bookNo(book), price(sales_price) {}

    std::string isbn() const {
        return bookNo;
    }
    virtual double net_price(std::size_t n) const {
        return n * price;
    }
    // virtual void debug(std::ostream &) const;

    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

// inline std::string Quote::isbn() const {
//     return bookNo;
// }

// inline double Quote::net_price(std::size_t n) const {
//     return n * price;
// }

// inline void Quote::debug(std::ostream &os) const {
//     os << "Book No: " << isbn() << ", price: " << price;
// }
#endif