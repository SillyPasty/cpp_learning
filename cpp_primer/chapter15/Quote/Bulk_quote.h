#ifndef BULK_QUOTE_HPP
#define BULK_QUOTE_HPP
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
    // Bulk_quote() = default;
    // Bulk_quote(const std::string& book, double p, std::size_t qty, double disc)
    //     : Disc_quote(book, p, qty, disc) {}
    using Disc_quote::Disc_quote;  // the same as previous lines
    double net_price(std::size_t) const override;
    void debug(std::ostream &) const override;
    virtual Bulk_quote *clone() const & {
        return new Bulk_quote(*this);
    }
    virtual Bulk_quote *clone() const && {
        return new Bulk_quote(std::move(*this));
    }

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

#endif