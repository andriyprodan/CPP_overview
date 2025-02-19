
## What is the purpose of the 'override' keyword in C++11 and later?
- To explicitly indicate that a function is overriding a virtual function from a base class

The 'override' keyword, introduced in C++11, is used to explicitly indicate that a function in a derived class is intended to override a virtual function from a base class. While it's not required for overriding to work, using 'override' provides several benefits: it clearly communicates the programmer's intent, helps catch errors where the function doesn't actually override as intended (e.g., due to a misspelled function name or incorrect parameter list), and improves code readability. If the function marked with 'override' doesn't actually override a virtual function, the compiler will generate an error, helping to catch potential bugs early in the development process.

## Virtual Inheritance (What problem does virtual inheritance solve in C++?)
https://www.geeksforgeeks.org/virtual-base-class-in-c/

## Pure Virtual Destructor (What is the correct way to define a pure virtual destructor in C++?)
    It's useful when you want an abstract base class but don't have any other functions that need to be pure virtual
https://www.geeksforgeeks.org/pure-virtual-destructor-c/