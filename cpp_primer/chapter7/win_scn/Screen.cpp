#include"Screen.h"
// inline cannot be defined in another file, althouth it has include the header *.

void Screen::some_member() const {
    ++access_ctr;
}
