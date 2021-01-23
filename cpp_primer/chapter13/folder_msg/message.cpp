#include "message.h"

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
    for (auto f : m.folders) {
        f->addMsg(this);  // folder's function
    }
}

void Message::remove_from_Folders() {
    for (auto f : this->folders) {
        f->remMsg(this);
    }
}

void Message::move_Folders(Message *m) {
    folders = std::move(m->folders);
    for (auto f : folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
    add_to_Folders(m);  // add new information into the folder.
}

Message::Message(Message &&m) : contents(std::move(m.contents)) {
    move_Folders(&m);
}

Message::~Message() {
    remove_from_Folders();
}

Message &Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message &Message::operator=(Message &&rhs) {
    if (this != &rhs) {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}
inline void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (auto f : lhs.folders) f->remMsg(&lhs);
    for (auto f : rhs.folders) f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders) f->addMsg(&lhs);
    for (auto f : rhs.folders) f->addMsg(&rhs);
}

void Message::addFolder(Folder *f) {
    folders.insert(f);
}

void Message::remFolder(Folder *f) {
    folders.erase(f);
}