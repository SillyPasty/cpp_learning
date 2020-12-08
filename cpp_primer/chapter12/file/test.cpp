#include "QueryResult.h"
#include "TextQuery.h"

void run_queries(std::ifstream &);

int main() {}

void run_queries(std::ifstream &infile) {
    TextQuery tq(infile);
    while (1) {
        std::cout << "Enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}
