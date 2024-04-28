# Виділяй пам'ять на стеку кожного разу, коли можливо, бо це набагато швидше


```cpp
#include <iostream>
#include <string>

struct Vector3 {
    float x, y, z;

    Vector3() 
        : x(10), y(11), z(12) {
    }
};

int main() {
    // stack allocation
    int value = 5;

    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;

    Vector3 vector;

    // heap allocation
    int* hvalue = new int;
    *hvalue = 5;

    int harray = new int[5];

    Vector3* hvector = new Vector3;

    delete hvalue;
    delete[] harray;
    delete hvector;

    std::cin.get();
}