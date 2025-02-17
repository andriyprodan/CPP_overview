```cpp
#include <iostream>
#include <string>

class Entity {
private:
    std::string m_Name;
    mutable int m_DebugCount = 0; // can be changed in a const method
public:
    const std::string& GetName() const {
        m_DebugCount++;
        return m_Name;
    }
};

int main() {
    const Entity e;
    std::cout << e.GetName() << std::endl;

    std::cin.get();
}
```

### Використання із lambda-функціями. Значення, які передаються за значенням (знак "=" в квадратних дужках) (в даному випадку - x), не можуть бути змінені в тілі функції.
Якщо не вказувати mutable, код не буде компілюватися.
```cpp
int main() {
    int x = 8;
    auto f = [=]() mutable {
        x++;
        std::cout << x << std::endl;
    };

    f(); // print 9
 }