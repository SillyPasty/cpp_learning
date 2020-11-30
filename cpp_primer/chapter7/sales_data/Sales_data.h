#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>
#endif

class Sales_data {
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

public:
    Sales_data(const std::string &s, unsigned n, double p)
        : book_no(s), units_sold(n), revenue(p * n) {}
    // Sales_data(): Sales_data("", 0, 0) {} // 构造函数委托

    // Sales_data() = default;
    Sales_data(const std::string &s = "") : book_no(s) {}  // include the default function
    // use explicit to prevent 隐式转换
    explicit Sales_data(std::istream &);

    std::string isbn() const {
        return book_no;
    }  // Indicate that the 'this' pointer in the function is a const pointer points to a
       // const value.
    Sales_data &combine(const Sales_data &);

private:
    double avg_price() const;
    std::string book_no;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

inline double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}
inline Sales_data::Sales_data(std::istream &is) : Sales_data() {
    read(is, *this);
};