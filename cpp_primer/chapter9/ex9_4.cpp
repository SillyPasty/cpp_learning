#include <vector>
using std::vector;

vector<int>::iterator find(int x);

int main() {
    vector<int> vec;
    auto result = find(vec, 5);
    if (result != vec.end())
        return 0;
    return 0;
}
vector<int>::iterator find(vector<int> v, int x) {
    auto iter = v.begin();
    while (iter != v.end()) {
        if (*iter == x)
            return iter;
        ++iter;
    }
    return iter;
}