#ifndef QUERY_HPP
#define QUERY_HPP

#include "QueryResult.hpp"
#include "Query_base.hpp"
#include "TextQuery.hpp"
#include "WordQuery.hpp"

// interface class
class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
    friend std::ostream &operator<<(std::ostream(&os), const Query &query);

public:
    Query(const std::string &);
    QueryResult eval(const TextQuery &t) const {
        return q->eval(t);
    }
    std::string rep() const {
        return q->rep();
    }

private:
    Query(std::shared_ptr<Query_base> query) : q(query) {}
    std::shared_ptr<Query_base> q;
};

inline Query::Query(const std::string &s) : q(new WordQuery(s)) {}

#endif