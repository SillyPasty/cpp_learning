#ifndef BULK_QUOTE_HPP
#define BULK_QUOTE_HPP
#include "Quote.h"

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc)
        : Quote(book, p), min_qty(qty), discount(disc) {}
    double net_price(std::size_t) const override;
    // void debug(std::ostream&) const override;

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

inline double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

// inline void Bulk_quote::debug(std::ostream& os) const {
//     Quote::debug(os);
//     os << ", min_qty: " << min_qty << ", discount: " << discount;
// }

#endif