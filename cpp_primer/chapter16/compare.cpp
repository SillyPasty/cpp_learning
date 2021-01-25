#include <iostream>

template <typename T>
int compare(const T &v1, const T v2) {
    if (v2 < v1) return -1;
    if (v1 < v2) return 1;
    return 0;
}

template <typename T, typename F>
int compare(const T &v1, const T &v2, F f) {
    if (f(v1, v2)) return -1;
    if (f(v2, v1)) return 1;
    return 0;
}

int main() {
    double x1 = 0, x2 = 10;
    int i1 = 1, i2 = 2;
    compare(x1, x2);
    compare(i1, i2);
    std::cout << compare(x1, x2,
                         [](const double &v1, const double &v2) { return v1 > v2; });
}