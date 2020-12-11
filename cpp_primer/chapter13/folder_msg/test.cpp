#include "message.h"

int main() {
    Folder f;
    Message msg("hello");
    msg.save(f);
}