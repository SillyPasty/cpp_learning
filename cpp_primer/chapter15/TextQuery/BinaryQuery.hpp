#ifndef BINARYQUERY_HPP
#define BINARYQUERY_HPP

#include "QUery.hpp"
#include "Query_base.hpp"
class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s)
        : lhs(l), rhs(r), opSym(s) {}
    std::string rep() const {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }

    Query lhs, rhs;
    std::string opSym;
};
#endif