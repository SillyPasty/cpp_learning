#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream input(argv[1]);
    vector<string> lines;
    string line;
    while (getline(input, line))
        lines.push_back(line);
    istringstream iss;
    for (auto iter = lines.begin(); iter != lines.end(); ++iter) {
        iss.str(*iter);
        string word;
        while (iss >> word)
            cout << word << " ";
        cout << endl;
        iss.clear();
    }
    return 0;
}