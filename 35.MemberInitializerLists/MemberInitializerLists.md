### Member Initializer Lists вказується в конструкторі класу після параметрів. Ініціалізація членів класу ПОВИННА проходити в тому порядку, в якому вони оголошені в класі.
```cpp
#include <iostream>
#include <string>

class Example {
public:
    const int m_Value;
    Example() {
        std::cout << "Created Entity!" << std::endl;
    }

    Example(int x) {
        std::cout << "Created Entity with " << x << "!" << std::endl;
    }

};

class Entity {
private:
    std::string m_Name;
    int m_Score;
    Example correct_Example;
    Example m_Example;
public:
    Entity(): m_Name("Unknown"), m_Score(0), correct_Example(8) { // the order of initialization is important
        // prints "Created Entity" and "Created Entity with 8"
        m_Example = Example(8); 
    } 

    Entity(const std::string& name): m_Name(name) {}

    const std::string& GetName() const {
        return m_Name;
    }
};

int main() {
    Entity e;
    std::cout << e.GetName() << std::endl;

    Entity e1("Cherno");
    std::cout << e1.GetName() << std::endl;

    std::cin.get();
}
```

Цей підхід працює швидше ніж присвоєння значень в тілі конструктора, бо відбувається один виклик конструктора, а не два (один для ініціалізації, інший для присвоєння значень). Це особливо важливо для класів, які мають багато полів. Це також дозволяє ініціалізувати константні поля класу. Як у прикладі з класом Example(m_Example). Для correct_Example викликається тільки конструктор з ініціалізатором.
