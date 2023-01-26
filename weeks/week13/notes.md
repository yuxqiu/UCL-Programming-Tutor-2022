# Week 13

## What is C++

> C++ is a general purpose programming language with a bias towards systems programming that
> - is a better C.
> - supports data abstraction.
> - supports object-oriented programming.
> - supports generic programming
>
> Bjarne Stroustrup, inventor of C++


### Brief History

- C with classes
- C++97
- C++11
- C++17
- C++20

The remaining notes focus on all versions up to and including C++17. For codes that are not recommended for real-world use, I will mark them with `NRW`.


## Hello World

```c++
#include <iostream>
using namespace std;

int main() {
    // NRW
    cout << "Hello, World!" << endl;
    return 0;
}
```

- `using namespace std;`

```c++
#include <iostream>

int main() {
    // NRW probably
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

- `operatore<<`


## string

In C, we have

```c
const char* msg = "Hello World";
```

In C++, we have a more powerful string library `std::string`

```c++
const std::string msg = "Hello World";
```

- Benefits
- Costs


### Pass string as a parameter

> Related files: [overload.cc](./attachments/code/overload.cc)

```c++
// NRW
void f(std::string s);
void f(std::string& s);
void f(const std::string& s);
```

- Reference
- Overloaded Function
- Overload Resolution


### IO

> Related files: [io.cc](./attachments/code/io.cc)

- cout
- cin
- cerr
- fstream
- stringstream


### String Operations

> Related files: [string.cc](./attachments/code/string.cc)

- Documentation
- Indexing
- Substring
- Search
- Concatenation
- Iterate (2 ways)


## OOP

### Representing points

> Related files: [Point.cc](./attachments/code/Point.cc)

- `struct` and `class`
- Access control
- Constructor
    - Initializer List
- Destructor
- Copy Constructor/Assignment


### Operator Overloading

> Related files: [operator.cc](./attachments/code/operator.cc)

- Add two points?
- Equality
- Output to stream
- `const`
    - `const` correctness


### Inheritance

> Related files: [inheritance.cc](./attachments/code/inheritance.cc)

- public inheritance
- virtual dispatch (compared with Java)
    - virtual destructor
    - casting
- `override` and `final`


## Template Programming

> Related files: [template.cc](./attachments/code/template.cc)

A generic `Point` class

- parameterized class and function
- STL (Standard Template Library)


## Trivial

### Exception

> Related files: [exception.cc](./attachments/code/exception.cc)

Supports Exception
- try
- catch
- throw

### Memory Management

> Related files: [memory.cc](./attachments/code/memory.cc)

- Why `malloc` is not enough
- `new`, `new []`, `delete`, and `delete[]`
- Array: order of construction/destruction
- RAII and Exception


### Revisiting Hello World

```c++
#include <iostream>

int main() {
    // NRW
    const std::string s = "Hello World";
    std::cout << s << std::endl;
    return 0;
}
```

- Namespace
- Template
- OOP
- Dynamic Memory Allocation (usually SSO)
- RAII
- Exception
- Overloaded Function
- IO
- Operator Overload


## Reference

This work was largely inspired by the CS106/CS106L course readings. If you want to learn more about C++, you can start here.