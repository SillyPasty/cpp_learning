#include <exception>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template <typename>
class Blob;

template <typename T>
std::ostream &operator<<(std::ostream &, Blob<T> &);
template <typename T>
class Blob {
    friend std::ostream &operator<<<T>(std::ostream &, Blob<T> &);

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T>);
    size_type size() const {
        return data->size();
    }
    bool empty() const {
        return data->empty();
    }
    void push_back(const T &t) {
        data->push_back(t);
    }
    void push_back(const T &&t) {
        data->push_back(std::move(t));
    }

    void pop_back();

    T &back();
    T &operator[](size_type i);

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
Blob<T>::Blob() try : data(std::make_shared<std::vector<T>>()) {
} catch (const std::bad_alloc &e) {
    std::cerr << e.what() << '\n';
}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) try
    : data(std::make_shared<std::vector<T>>(il)) {
} catch (const std::bad_alloc &e) {
    std::cerr << e.what() << '\n';
}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) throw std::out_of_range(msg);
}

template <typename T>
T &Blob<T>::back() {
    check(0, "back on empty blob");
    return data->back();
}

template <typename T>
T &Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty blob");
    data->pop_back();
}

template <typename T>
std::ostream &operator<<(std::ostream &os, Blob<T> &rhs) {
    return os << rhs.back();
}