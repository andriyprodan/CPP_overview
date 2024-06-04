```cpp
#include <iostream>

struct Entity {
    int x, y;

    int* GetPosition() {
        // we do this
        return &x;
        // instead of this
        // int* array = new int[2];
        // array[0] = x;
        // array[1] = y;
        // return array;
    }

}

int main() {
    Entity e = {5, 8};

    int* position = (int*) &e; // converts Entity to array of two integers    
    std::cout << position[0] << ", " << position[1] << std::endl; // prints 5, 8

    
    int* position2 = e.GetPosition(); // same as above
    position2[0] = 2; // changes x
    std::cout << position2[0] << ", " << position2[1] << std::endl; // prints 2, 8

    std::cin.get();
}
```