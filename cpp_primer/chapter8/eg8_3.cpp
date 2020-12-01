#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::vector;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    string line, word;
    vector<PersonInfo> people;
    while (getline(cin, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &person : people) {
        ostringstream formatted, bad_nums;
        for (const auto &nums : person.phones) {
            if (nums.size() != 11)
                bad_nums << nums << " ";
            else
                formatted << nums << " ";
        }
        if (bad_nums.str().empty())
            cout << person.name << " " << formatted.str() << endl;
        else
            cout << "input error:" << bad_nums.str() << endl;
    }
    return 0;
}