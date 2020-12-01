#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream input(argv[1]);
    vector<string> buffer;
    if (input) {
        string tmp;
        // while (input >> tmp)
        while (getline(input, tmp))
            buffer.push_back(tmp);
    } else {
        cerr << "could not open file!" << endl;
    }
    for (auto iter = buffer.begin(); iter != buffer.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}