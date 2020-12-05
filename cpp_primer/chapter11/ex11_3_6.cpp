#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

void word_transform(ifstream &, ifstream &);
map<string, string> build_map(ifstream &);
const string &transform(const string &, const map<string, string> &);

int main() {
    ifstream m_file("map"), input("input");
    word_transform(m_file, input);
    return 0;
}

map<string, string> build_map(ifstream &map_file) {
    map<string, string> word_map;
    string k, v, line;
    while (map_file >> k && getline(map_file, line)) {
        if (line.size() <= 1)
            throw runtime_error("No rules for " + k);
        word_map[k] = line.substr(1);
    }
    return word_map;
}

void word_transform(ifstream &map_file, ifstream &input) {
    auto word_map = build_map(map_file);
    string line;
    while (getline(input, line)) {
        istringstream is(line);
        string word;
        bool first_word = true;
        while (is >> word) {
            if (first_word)
                first_word = false;
            else
                cout << " ";
            auto trans = transform(word, word_map);
            cout << trans;
        }
        cout << endl;
    }
}

const string &transform(const string &text, const map<string, string> &word_map) {
    auto iter = word_map.find(text);
    if (iter != word_map.cend())
        return iter->second;
    return text;
}