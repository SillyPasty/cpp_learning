#include <memory>
using namespace std;

int main() {
    int x = 2;
    unique_ptr<int> up(new int(x));
    unique_ptr<int> up1 = up;  // wrong
}