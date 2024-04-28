### Arrow Operator
```cpp
#include <iostream>
#include <string>

class Entity {
public:
    int x;
    void Print() const {
        std::cout << "Hello!" << std::endl;
    }
};

int main() {
    Entity e;
    e.Print();

    // or
    Entity* ptr = &e; // & is used to get the address of the object
    (*ptr).Print(); // dereferencing the pointer

    // or
    Entity& entity = *ptr; // dereferencing the pointer and storing the result in a reference
    entity.Print();

    // or
    ptr->Print(); // arrow operator
    

    std::cin.get();
}
```

### Arrow Opearator overloading for Scoped Pointer
```cpp
#include <iostream>
#include <string>

class Entity {
public:
    int x;
    void Print() const {
        std::cout << "Hello!" << std::endl;
    }
};

class ScopedPtr {
private:
    Entity* m_Ptr;
public:
    ScopedPtr(Entity* ptr): m_Ptr(ptr) {}
    ~ScopedPtr() {
        delete m_Ptr;
    }

    Entity* operator->() {
        return m_Ptr;
    }
};


int main() {
    ScopedPtr entity = new Entity();
    entity->Print(); // using overloaded arrow operator to call the Print function of the Entity class 

    std::cin.get();
}
```

### Arrow Operator for getting offset in memory of a struct (class) member
```cpp
struct Vector3 {
    float x, y, z;
}

int main() {
    int offset = (int)&((Vector3*) nullptr)->x;
    std::cout << offset << std::endl; // prints 0

    offset = (int)&((Vector3*) nullptr)->y;
    std::cout << offset << std::endl; // prints 4 (size of float)

    offset = (int)&((Vector3*) nullptr)->z;
    std::cout << offset << std::endl; // prints 8 (size of float * 2)

    std::cin.get();
}
```