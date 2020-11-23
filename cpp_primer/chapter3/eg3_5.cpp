#include<iostream>
#include<cstddef>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::size_t;
int main()
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *beg = std::begin(array);
    int *end = std::end(array);
    int *parray[10]; // pointer array
    int (*Parray)[10] = &array; //a pointer to the array
    int (&Rarray)[10] = array;
    // int (*P2array) = &array;
    cout << *Parray << endl;
    cout << (Parray[0] + 10) << endl;
    cout << Parray[1] << endl;
    cout << Rarray[0] << endl;
    cout << Rarray[1] << endl;
    string s("hello world!");
    const char *str = s.c_str();
    cout << str << endl;
    s[2] = 'x';
    cout << str << endl;
    return 0;
}