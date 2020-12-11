#ifndef MESSAGE_H
#define MESSAGE_H
#include <set>
#include <string>

#include "folder.h"
class Folder;
class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);

public:
    explicit Message(const std::string &str = "") : contents(str) {}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();
    void save(Folder &);
    void remove(Folder &);

private:
    void addFolder(Folder *);
    void remFolder(Folder *);
    std::string contents;
    std::set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

#endif