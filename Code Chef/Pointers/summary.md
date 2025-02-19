## Which of the following is the correct way to initialize a null pointer in modern C++?
- int *ptr = nullptr;

In modern C++ (C++11 and later), the correct way to initialize a null pointer is using 'nullptr'. The 'nullptr' keyword is a pointer literal that represents a null pointer. It's type-safe and helps avoid ambiguities that can occur with NULL or 0. While 'int *ptr = 0;' and 'int *ptr = NULL;' are still valid in C++, 'nullptr' is the preferred method as it's more expressive and safer, especially in template code and overload resolution contexts.

## Властивості references
- References must be initialized when declared.
- References cannot be reassigned to refer to different variables
- References cannot be null 
- References provide an alias to an existing variable