#ifndef FOLDER_H
#define FOLDER_H
#include <set>
class Message;
class Folder {
    friend class Message;

public:
    Folder() = default;
    void addMsg(Message *);
    void remMsg(Message *);

private:
    std::set<Message *> messages;
};

#endif