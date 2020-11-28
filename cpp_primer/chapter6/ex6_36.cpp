#include <string>
using std::string;

string (&foo0(string s))[10];

typedef string (&r_str)[10];
r_str foo1(string s);

auto foo2(string s) -> string (&)[10];  // 尾置返回类型

string (&s_r)[10];
decltype(s_r) foo3(string s);
