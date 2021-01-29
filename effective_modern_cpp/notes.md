

# Chapter1-Deducing Types

## Item1-Template type deduction

- Template type deduction

```c++
template <typename T>
void f(ParamType param);
```

### Param Type is a pointer or reference

```c++
template <typename T>
void f(T& param);

int x = 27;
const int cx = x;
const int& rx = x;

f(x);  // T is int, ParamType is int&
f(cx); // T is const int, ParamType is const int&
f(rx); // T is const int, ParamType is const int&
```

```c++
template <typename T>
void f(const T& param);

int x = 27;
const int cx = x;
const int& rx = x;

f(x);  // T is int, ParamType is const int&
f(cx); // T is int, ParamType is const int&
f(rx); // T is int, ParamType is const int&
```

### Param Type is a universal reference

```c++
template <typename T>
void f(T&& param);

int x = 27;
const int cx = x;
const int& rx = x;

f(x);  // T is int&, ParamType is int&
f(cx); // T is const int&, ParamType is const int&
f(rx); // T is const int&, ParamType is const int&
f(27); // T is int, ParamType is int&&
```

### Param Type is neither a pointer nor a reference

```c++
template <typename T>
void f(T param);

int x = 27;
const int cx = x;
const int& rx = x;

f(x);  // T is int, ParamType is int
f(cx); // T is int, ParamType is int
f(rx); // T is int, ParamType is int
```

### Arrays

```c++
template <typename T>
void f(T param);

template <typename T>
void fr(T& param);

const char name[] = "yubo wang";
f(name);  // T is const char *
fr(name); // T is const char[10], ParamType is const char(&)[10]
```

### Functions

```c++
template <typename T>
void f(T param);

template <typename T>
void fr(T& param);

void myFunc(int, double);
f(myFunc);  // T is void(*)(int, double);
fr(myFunc); // T is void(&)(int, double);
```

### Remark

- If a pointer is a **const** pointer points to a **const** value, and the pointer is passed to a function by value, the pointer's **const** will be ignored, the value's **const** is still existed.

## Item2-Auto type deduction

- **auto** type deduction is usually the same as template type deduction, but **auto** type deduction assumes that a braced initializer represents a **std::initializer_list**, and template type deduction does not.
- **auto** in a function return type or a lambda parameter implies template type deduction, not **auto** deduction

## Item3-Decltype

- For lvalues expressions of type T other than names, **decltype** always reports a type of T&

```c++
template<typename Container, typename Index>
decltype(auto)
authAndAccess(Container&& c, Index i) {
    authUser();
    return std::forward<Container>(c)[i];
}
```

## Item4-How to view deduced types

- IDE, Complier, Runtime
- Using typeid(xxx).name() may not be reliable, because **std::type_info::name** treats the type as pass_by_values parameter, which will ignore **const** and **&**

```c++
#include <boost/type_index.hpp>

template <typename T>
void f(const T& param) {
    using std::cout;
    using boost::typeindex::type_id_with_cvr;
    cout << "T =     " << type_id_with_cvr<T>().pretty_name() << '\n';
    cout << "param = " << type_id_with_cvr<decltype<param>>().pretty_name() << '\n';
}
```

# Chapter2-auto

## Item5-auto to explicit type declarations

- **auto** is good -- most of the time..

## Item6-use the explicitly typed initializer idiom when auto deduces undesired types

- **vector<bool\>** will return **std::vector<bool\>::reference** because c++ does not allow reference to a bit.
  - proxy class -- invisible proxy types
  - can cause **auto** to reduce the wrong type
- For numeric code, there will be more proxy classes
- use **static_cast<>** to prevent
  - The explicitly typed initializer idiom forces **auto** to deduce the type you want it to have

```c++
std::vector<bool> features(const Widget& w);
Widget w;

auto pri = static_cast<bool>(features(w)[5]); // good and right!
```

