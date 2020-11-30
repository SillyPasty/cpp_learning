#include<iostream>
#include<fstream>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;
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