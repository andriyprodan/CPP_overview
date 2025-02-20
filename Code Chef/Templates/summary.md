## Template Specialization (What is the purpose of template specialization?)
https://www.geeksforgeeks.org/template-specialization-c/

## Template Parameter Deduction
In which scenario does template argument deduction occur?

- Only for function templates

Template argument deduction occurs automatically for function templates but not for class templates. When calling a function template, the compiler can deduce the template arguments from the function arguments. For example:
```cpp
template <typename T>
void print(T value) {
    std::cout << value << std::endl;
}

print(42);  // T is deduced as int
print(3.14); // T is deduced as double
```
For class templates, you must explicitly specify the template arguments when instantiating the class. 

## Variadic Templates (What feature of C++ allows a template to accept an arbitrary number of arguments?)
https://www.geeksforgeeks.org/variadic-function-templates-c/

## Template Metaprogramming (What is a primary characteristic of template metaprogramming?)
    Template Metaprogramming is generally not used in practical programs, it is an interesting concept though.
    
https://www.geeksforgeeks.org/template-metaprogramming-in-c/