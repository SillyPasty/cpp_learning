

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

# Chapter3-Modern C++

## Item7 (), {}, =

- Braced initialization is the most widely usable initialization syntax, it prevents **narrowing conversions**, and it's **immune to c++'s most vexing parse**.
  - Widge w(); Is a declaration of a function
  - Widge w{}; The ctor of the class
- During the constructor overload resolution, braced initializers are matched to **std::initializer_list** parameters if at all possible, even if other constructors offer seemingly better matched.

## Item8 Prefer nullptr to 0 and NULL

- neither 0 or NULL has a pointer type?
- When you want to refer to a null pointer, use **nullptr**
- 0 and NULL are **int** or **int-like-type**

## Item9 Prefer using to typedefs

```c++
typedef void *(FP)(int, const std::string&);
using FP = void (*)(int, const std::string&);

template<typename T>
using MyAlllocList = std::list<T, MyAlloc<T>>;

template<typename T>
struct MyAllocList {
    typedef std::list<T, MyAlloc<T>> type;
}
// MyAllocList<int> VS MyAllocList<int>::type
```

- using support templates!
- Alias avoid the **::type** and **typename** needed by dependent type
  - Because for different T of the template, **::type** may be different (even not type!), so **typename** is needed in dependent type.

## Item10 Prefer scoped enums to unscoped enums

- Scoped ads

  - Do not leak
  - Prevent implicitly convert
  - May be forward-declared

- Because of the prevention of implicitly convert, we can use

  ```c++
  template<typename E> // C++14
  constexpr std::underlying_type_t<E>
  toUType(E enumerator) noexcept
  {
  	return static_cast<std::underlying_type_t<E>>(enumerator);
  }
  
  auto val = std::get<toUType(UserInfoFields::uiEmail)>(uInfo); // uInfo is a tuple, UserInfoFields is an enum
  ```

## Item11 Delete

- delete can be used to prevent the use of some template

```c++
template<typename T>
void processPointer(T* ptr);

template<>
void processPointer<void>(void*) = delete;
template<>
void processPointer<char>(char*) = delete;
```

- Prefer deleted functions to private undefined ones

## Item12 Declare overriding function *override*

- For overriding to occur, serval requirements must be met
  - The base class function must be virtual
  - The base and derived function names must be identical (except in the case of destructors)
  - The parameter types of the base and derived functions must be identical
  - The constness of the base and derived functions must be identical
  - The return types and exception specifications of the base and derived functions must be compatible.
  - The functions' reference qualifiers must be identical. (the limit of *this*)
- Use declare the overriding function **override** !!!
  - Allow compliers to detect mistakes
  - Less test when changing function signature

## Item13 Prefer *const_iterators* to *iterators*

- Prefer **const_iterators** to **iterators**
- Prefer non-member versions of **begin end rbegin**
  - Some third-party libraries only have non-member function.

## Item14 *noexcept*

- optimizers need not keep the runtime stack in an unwindable state, nor must they ensure that objects in a **noexcept** function are destroyed in the inverse order of construction should an exception leave the function.
- Exception-neutral functions are never **noexcept**, because they may emit passing through exceptions.
- **noexcept** is particularly valuable for the move operations, **swap**, memory deallocation functions and destructors.
  - For example, vector will only use **move** for the elements with **noexcept ** moving constructer, when its space is not enough.

## Item15 Use *constexpr* whenever possible

- **constexpr** objects are **const** and are initialized with values known during compilation
- **constexpr** functions can produce compile-time results when called with arguments whose values are known during compilation

## Item16 Make *const* member functions thread safe

- mutable
  - a **mutable** in a class can be modified by a **const** function.
  - **mutable** allows lambda to change the variable out of its range.
- Use of **std::atomic** variables may offer better performance than a mutex, but they are suited for manipulation of only a single variable or memory location. (Two atomic executions are not atomic!)

## Item17 Understand special member function generation

- Special members: **constructor, destructor, copy operations, move operations**
- **Move operations** are generated only for classes lacking explicitly declared move operations, copy operations, and a destructor.
- **Copy constructor** is generated only for classes lacking an explicitly declared copy constructor, and it's deleted if a move operation is declared.
- **Copy assignment operator** is generated only for classes lacking an explicitly declared copy assignment operator, and it's deleted if a move operation is declared. Generation of the copy operations in classes with an explicitly declared destructor is deprecated.
- Member function templates never suppress generation of special member functions
- Can use explicitly defined **=default** to tell the complier to create the members.