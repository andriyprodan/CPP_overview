#include <iostream>

class Entity {
public:
    int example_stack[5]; // this memory is allocated inside of the memory of the class
     // this memory is allocated in some other place in the memory than Entity class. Entity class only contains memory address of this pointer. So to access this memory from the class we need to jump into other place in the memory which is not so efficient as the stack allocated array.
    int* example_heap = new int[5];

    Entity() {
        for (int i = 0; i < 5; i++) {
            example_stack[i] = 2;
        }
    }
};

int main() {
    Entity e;

    std::cin.get();
}