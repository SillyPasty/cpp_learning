#ifndef QUOTE_HPP
#define QUOTE_HPP
#include <iostream>
#include <string>
class Quote {
    friend double print_total(std::ostream &, const Quote &, size_t);

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
    virtual void debug(std::ostream &) const;
    virtual Quote *clone() const & {
        return new Quote(*this);
    }
    virtual Quote *clone() const && {
        return new Quote(std::move(*this));
    }
    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

#endif