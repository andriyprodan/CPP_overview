```cpp
#include <iostream>
#include <string>

class Entity {
public:
    int x;
    Entity() {
        std::cout<< "Created Entity" << endl;
    }

    ~Entity() {
        std::cout<< "Destroyed Entity" << endl;
    }
}

int* CreateArray() {
    int array[50];
    return array; // видасть помилку компіляції, бо масив array знищиться після виходу з функції
}

int* AllocateArray() {
    int* array = new int[50];
    return array; 
}

int main() {
    {
        Entity e; // prints "Created Entity"
    }
    // prints "Destroyed Entity". Memory has been freed.

    {
        Entity* e = new Entity(); // prints "Created Entity"
    }
    // prints nothing. Memory has not been freed.

    int* a = CreateArray(); // видасть помилку компіляції, бо масив array знищиться після виходу з функції
    // correct way:
    int* correctArray = AllocateArray();
    // or

    

    std::cin.get();
    // prints "Destroyed Entity" for variable *e*. Memory has been freed when the program ends.
}
```

### Custom unique (scoped) pointer. Такі штуки можна використовувать, щоб автоматично звільнять пам'ять, що була виділена в купі.
```cpp
class ScopedPtr {
private:
    Entity* m_Ptr;
public:
    ScopedPtr(Entity* ptr): m_Ptr(ptr) {}
    ~ScopedPtr() {
        delete m_Ptr;
    }
}

int main() {
    {
        ScopedPtr e = new Entity(); // implicit conversion (part 39) from Entity* to ScopedPtr
    }
    // prints "Destroyed Entity", memory has been freed in the destructor of ScopedPtr
    std::cin.get();
}
```