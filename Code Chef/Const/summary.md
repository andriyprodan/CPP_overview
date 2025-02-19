## Which of the following is true about const member functions in C++?
- They can be overloaded based on their const-ness

Const member functions can be overloaded based on their const-ness. This means you can have two versions of the same function, one const and one non-const. The const version will be called for const objects, while the non-const version will be called for non-const objects. Const member functions cannot modify non-static data members or call non-const member functions. However, they can modify static data members as static members are not associated with any particular object instance.

## What does 'logical constness' mean in C++?
- A const object can be modified, but only in ways that are not observable from outside the object

Logical constness in C++ means that a const object can be modified, but only in ways that are not observable from outside the object. This concept recognizes that some changes to an object's internal state don't affect its logical state as perceived by the user. For example, caching a computed value in a const member function doesn't change the logical state of the object, even though it modifies a member variable. The mutable keyword is often used to implement logical constness, allowing specific members to be modified even in const contexts.

## Consider the following class declaration:
```cpp
class Example {
public:
    void func() { }
    void func() const { }
};
```
How many distinct functions are declared in this class?

 - 2

This class declaration contains 2 distinct functions. In C++, member functions can be overloaded based on their const-ness. The first func() is a non-const member function that can be called on non-const objects. The second func() const is a const member function that can be called on const objects or const references/pointers to objects. This allows for different behavior depending on whether the object is const or not. When a non-const object calls func(), the non-const version will be called. When a const object calls func(), the const version will be called.
