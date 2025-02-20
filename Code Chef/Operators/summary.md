## Overloading Assignment Operator (What is a key consideration when overloading the assignment operator (=)?)
https://www.geeksforgeeks.org/cpp-assignment-operator-overloading/
[Memcpy/Memmove](../memcpy_memmove/summary.html)  
https://www.geeksforgeeks.org/copy-swap-idiom-c/

## Overloading Comparison Operators (When overloading comparison operators (e.g., <, >, ==), what is a good practice to follow?)
- Implement only the '<' operator and derive others from it
A good practice when overloading comparison operators is to implement the '<' operator and derive the others from it. This approach, known as the 'canonical implementation', reduces code duplication and ensures consistency. Once '<' is implemented, you can define the other operators in terms of it:
```cpp
bool operator>(const ClassName& lhs, const ClassName& rhs) { return rhs < lhs; }
bool operator<=(const ClassName& lhs, const ClassName& rhs) { return !(rhs < lhs); }
bool operator>=(const ClassName& lhs, const ClassName& rhs) { return !(lhs < rhs); }
bool operator==(const ClassName& lhs, const ClassName& rhs) { return !(lhs < rhs) && !(rhs < lhs); }
bool operator!=(const ClassName& lhs, const ClassName& rhs) { return (lhs < rhs) || (rhs < lhs); }
```
This approach is both efficient and maintains logical consistency across all comparison operations.
Всі інші оператори викликають перевизначений оператор '<' і використовують його результат для визначення власного.

# Overloading Subscript Operator
https://www.geeksforgeeks.org/overloading-subscript-or-array-index-operator-in-c/

# Overloading Function Call Operator
What is a common use case for overloading the function call operator (())?
- To implement a functor  
  
A common use case for overloading the function call operator (()) is to implement a functor, also known as a function object. A functor is an object that can be used with function call syntax. This is useful in many scenarios, particularly with the Standard Template Library (STL) algorithms. Functors can maintain state between calls and can be more efficient than function pointers. For example:
```cpp
class Adder {
private:
    int total;
public:
    Adder() : total(0) {}
    int operator()(int value) {
        total += value;
        return total;
    }
};

Adder myAdder;
cout << myAdder(10) << endl;  // Outputs 10
cout << myAdder(20) << endl;  // Outputs 30
```
In this example, the Adder class is a functor that keeps a running total of the values passed to it.