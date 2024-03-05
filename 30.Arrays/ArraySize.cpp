#include <iostream>

int main() {
    int a[5];
    // how to find the number of elements in an stack allocated array
    int count = sizeof(a) / sizeof(int); // 20 / 4 = 5

    int* b = new int[5];
    // how to find the number of elements in an heap allocated array
    // THIS WILL NOT WORK
    int count2 = sizeof(b) / sizeof(int*); // 8 / 8 = 1, first 8 is the size of the integer pointer, second 8 is the size of the integer

    // CORRECT WAY:
    const int size = 5;
    int* c = new int[size];

    for (int i = 0; i < size; i++) {
        c[i] = 2;
    }

    std::cin.get();
}