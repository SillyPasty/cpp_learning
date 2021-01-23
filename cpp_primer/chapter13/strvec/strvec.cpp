#include "strvec.h"

#include <algorithm>
#include <iterator>
#include <memory>
#include <utility>

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b,
                                                             const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (!elements) return;
    // for_each(begin(), end(), [&](auto p) -> void { alloc.destroy(p); });
    for (auto p = first_free; p != elements;) alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
}

StrVec::StrVec(const StrVec &s) {
    auto new_data = alloc_n_copy(s.begin(), s.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec::StrVec(StrVec &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec::~StrVec() {
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    auto last = std::uninitialized_copy(make_move_iterator(begin()),
                                        make_move_iterator(end()), first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

void StrVec::resize(size_t newsize) {
    auto newcapacity = newsize;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    // move old to new
    for (size_t i = 0; i != size() && i != newcapacity; ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reverse() {
    auto b = begin();
    auto e = end();
    --e;
    while (b < e) {
        std::swap(*b, *e);
        ++b;
        --e;
    }
}