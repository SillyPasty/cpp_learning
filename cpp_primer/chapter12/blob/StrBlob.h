#ifndef STRBLOB
#define STRBLOB
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> i1);
    size_type size() const {
        return data->size();
    }
    bool empty() const {
        return data->empty();
    }
    // add and remove elements
    void push_back(const std::string& t) {
        data->push_back(t);
    }
    void pop_back();
    // access elements
    std::string& front() const;
    std::string& back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string& msg) const;
};

#endif