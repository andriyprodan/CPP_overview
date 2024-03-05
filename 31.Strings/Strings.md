#### Якщо не використовується слово new, то не треба писати delete

```
#include <iostream>

int main() {
    const char* name = "Cherno"; // immutable string, this is not heap allocated
    // delete name; // error: cannot delete expression of type 'const char *'; no destructor called

    std::cin.get();
}
```