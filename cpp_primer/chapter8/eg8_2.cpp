#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::ostream;
using std::string;
int main(int argc, char* argv[]) {
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);
    if (!output) {
        std::cerr << "couldn't open file " << argv[2] << endl;
        return 0;
    }
    string s;
    input >> s;
    cout << "Write " << s << " to file " << argv[2] << endl;
    output << s;
    output.close();
    input.close();
    return 0;
}