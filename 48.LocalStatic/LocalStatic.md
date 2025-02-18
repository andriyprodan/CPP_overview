### Local static variable - змінна, що має час життя від початку виконання програми до її завершення, але доступна лише в межах (**scope**s)(функції, класу, if-else і т.д.) , в якій вона оголошена.

У Function змінна `i` залишається в пам'яті після виходу з функції, але доступна лише в межах функції Function.

```cpp
#include <iostream>

void Function() {
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

int main() {
    Function(); // prints 1
    Function(); // prints 2
    Function(); // prints 3

    std::cin.get();
}
```

Інший приклад

```cpp
#include <iostream>

class Singleton {
private:
    static Singleton* s_Instance;
public:
    static Singleton& Get() {
        return *s_Instance;
    }

    void Hello() {}
}

Singleton* Singleton::s_Instance = nullptr;

int main() {
    Singleton::Get().Hello();
    std::cin.get();
}
```

Як це можна зробити по-іншому:
```cpp
#include <iostream>

class Singleton {
public:
    static Singleton& Get() {
        static Singleton instance;
        return instance;
    }

    void Hello() {}
}

int main() {
    Singleton::Get().Hello();
    std::cin.get();
}
```