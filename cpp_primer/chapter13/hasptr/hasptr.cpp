#include "hasptr.h"

#include <iostream>

HasPtr::HasPtr(const HasPtr &orig)
    : i(orig.i), ps(new std::string(*(orig.ps))), use(orig.use), index(index_counter++) {
    ++*use;
    std::cout << "Copy constructor is called!" << std::endl;
}

HasPtr &HasPtr::operator=(HasPtr rhs) {
    std::cout << "Copy operator is called!" << std::endl;
    swap(*this, rhs);
    return *this;
}

// HasPtr &HasPtr::operator=(const HasPtr &rhs) {
//     std::cout << "Copy operator is called!" << std::endl;
//     ++*rhs.use;
//     if (--*use == 0) {
//         delete ps;
//         delete use;
//     }
//     ps = rhs.ps;
//     i = rhs.i;
//     use = rhs.use;
//     // auto newps = new std::string(*rhs.ps);
//     // i = rhs.i;
//     // index = rhs.index;
//     // delete ps;
//     // ps = new std::string(*newps);
//     return *this;
// }

HasPtr::~HasPtr() {
    std::cout << "Destructor is called!" << std::endl;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

int HasPtr::index_counter = 0;

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "HasPtr swap called!" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    swap(lhs.use, rhs.use);
}