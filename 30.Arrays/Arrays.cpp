#include <iostream>

int main() {
    // it's a pointer to the first element of the array
    // Stack allocated array. This array gets destroyed when the FUNCTION ends
    int example[5]; 
    
    int* ptr = example;

    for (int i = 0; i < 5; i++) {
        example[i] = 2;
    }

    example[2] = 5;
    // Same as previous row. Increment the pointer by the size of two integers or 8 bytes (pointer type) to access the third array's element.
    *(ptr + 2) = 6; 
    // Same as previous row.  Increment the pointer by the size of 8 chars or 8 bytes (casted pointer type) to access the third array's element.
    *(int*)((char*)ptr + 8) = 8; 


    std::cout << example[0] << std::endl;   // prints 2
    std::cout << example << std::endl;     // prints the memory address of the first element
    std::cout << example[2] << std::endl;  // prints 8

    // heap allocated array. This array gets destroyed when the PROGRAM ends or when we DELETE it using the delete keyword.
    // For example, use it in case when you return array from the function.
    int* another = new int [5];
    for (int i = 0; i < 5; i++) {
        another[i] = 2;
    }

    delete[] another;

    std::cin.get();
}