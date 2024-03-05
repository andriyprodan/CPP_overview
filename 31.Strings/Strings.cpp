#include <iostream>

int main() {
    const char* name = "Cherno"; // immutable string, this is not heap allocated
    // delete name; // error: cannot delete expression of type 'const char *'; no destructor called
    // name[2] = 'a'; // error: read-only variable is not assignable

    std::cout << name << std::endl; // prints Cherno

    char name2[6] = {'C', 'h', 'e', 'r', 'n', 'o'}; // mutable string, this is stack allocated
    std::cout << name2 << std::endl; // prints Cherno and some garbage, because the array is not null-terminated. std::cout doesn't know when to stop printing the array.

    // Correct way for the previous example
    char name3[7] = {'C', 'h', 'e', 'r', 'n', 'o', 0}; // mutable string, this is stack allocated
    std::cout << name3 << std::endl; // prints Cherno

    std::cin.get();
}