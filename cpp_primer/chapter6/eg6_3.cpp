#include <iostream>
int (*func0(int i))[10];           // return a pointer of an array with length 10.
auto func1(int i) -> int (*)[10];  // the same with func0