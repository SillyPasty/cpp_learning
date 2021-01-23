#ifndef HASPTR_H
#define HASPTR_H
#include <string>

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0), use(new std::size_t(1)), index(index_counter++) {}
    HasPtr(const HasPtr &);
    // HasPtr &operator=(const HasPtr &);
    HasPtr &operator=(HasPtr);
    int get_index() {
        return index;
    }

    std::size_t get_use() {
        return *use;
    }
    ~HasPtr();

private:
    int i;
    int index;
    std::string *ps;
    std::size_t *use;
    static int index_counter;
    // static int initCounter() {return}
};

#endif