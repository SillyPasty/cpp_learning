#ifndef NOTQUERY_HPP
#define NOTQUERY_HPP

#include "Query.hpp"
#include "Query_base.hpp"

class NotQuery : public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q) : query(q) {}
    std::string rep() const {
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery &) const;
    Query query;
};

inline Query operator~(const Query &operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}
#endif