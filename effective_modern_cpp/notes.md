

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