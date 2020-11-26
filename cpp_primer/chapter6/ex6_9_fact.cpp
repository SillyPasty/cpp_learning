#include"chapter6.h"
int fact(int x) {
    int ret = 1;
    while (x)
        ret *= x--;
    return ret;
}