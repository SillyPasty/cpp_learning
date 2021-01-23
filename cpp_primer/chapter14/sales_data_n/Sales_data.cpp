#include "Sales_data.h"

Sales_data Sales_data::operator+(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
}





