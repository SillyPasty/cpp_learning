#include "Query.hpp"

#include <iostream>
std::ostream &operator<<(std::ostream(&os), const Query &query) {
    return os << query.rep();
}