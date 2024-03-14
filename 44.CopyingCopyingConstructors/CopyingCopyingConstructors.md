```cpp
#include <iostream>
#include <string>

struct Vector2 {
    float x, y;
};

int main() {
    Vector2 a = {2, 3};
    Vector2 b = a; // copy constructor is called
    b.x = 5;
    std::cout << a.x << std::endl; // prints 2
    std::cout << b.x << std::endl; // prints 5

    Vector2* c = new Vector2();
    Vector2* d = c; // copy constructor is not called
    d->x = 5; // c->x is also 5

    std::cin.get();
}
```

### Another example. Custom String class
```cpp
#include <iostream>
#include <string>

class String {
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string) {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1]; // +1 for the null terminator
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0; // guarantee null-termination for the newly created buffer
    }

    ~String() {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index) {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string); // now we can use private members of String in the overloaded operator<< function
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
    stream << string.m_Buffer;
    return stream;
}

int main() {
    String string = "Cherno";
    String second = string;
    std::cout << string << std::endl;
    // m_Buffer is the same pointer for both instances of String
    // so when the destructor of *second* is called, it will try to delete the *m_Buffer* that was already deleted by the destructor of *string*
    // this will cause a runtime error
    std::cout << second << std::endl; 

    second[2] = 'a'; // this changes the *m_Buffer* of *second* and *string* as well
    std::cout << string << std::endl; // prints "Charno"
    std::cout << second << std::endl; // prints "Charno"

    
    std::cin.get();
}
```

Для того, щоб виправити цю помилку, потрібно визначити **конструктор копіювання** та **оператор присвоєння**. Це дозволить копіювати вміст *m_Buffer* в новий буфер для кожного об'єкта. Це називається **deep copy**.

```cpp
#include <iostream>
#include <string>

class String {
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string) {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1]; // +1 for the null terminator
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0; // guarantee null-termination for the newly created buffer
    }

    String(const String& other) = delete; // we delete the default copy constructor that copies only pointer of the m_Buffer 
    String(const String& other): m_Size(other.m_Size) { // correct copy constructor (deep copy)
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String() {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index) {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string); // now we can use private members of String in the overloaded operator<< function
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
    stream << string.m_Buffer;
    return stream;
}

void PrintString(const String& string) {
    string[2] = 'a'; // this will cause a compilation error because the function parameter is a const reference
    std::cout << string << std::endl;
}

int main() {
    String string = "Cherno";
    String second = string;
    second[2] = 'a'; 

    PrintString(string); // prints "Cherno"
    PrintString(second); // prints "Charno"

    // no runtime error because m_Buffer of *second* is different from m_Buffer of *string*
    
    std::cin.get();
}
```