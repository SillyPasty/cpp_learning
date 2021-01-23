#include "Bulk_quote.h"

void Bulk_quote::debug(std::ostream &os) const {
    Quote::debug(os);
    os << ", min_qty: " << min_qty << ", discount: " << discount;
}