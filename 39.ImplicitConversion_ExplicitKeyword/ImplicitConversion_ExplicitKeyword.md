### implicit conversion - неявне перетворення типу. Це перетворення може викликатися при створенні екземляру класу. Може викликатися тільки раз. Якщо вираз містить більше одного неявного перетворення, то воно не відбудеться.
```cpp
#include <iostream>
#include <string>

class Entity {
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string& name): m_Name(name), m_Age(-1) {}
    Entity(int age): m_Name("Unknown"), m_Age(age) {}

}

void PrintEntity(const Entity& entity) {
    std::cout << entity.GetName() << std::endl;
}

int main() {
    // implicit conversion
    Entity a = "Andriy";
    Entity b = 22;

    // Literal 22 is implicitly converted to Entity(22)
    PrintEntity(22);

    std::cin.get();
}
```
З літералом "Andriy" implicit conversion не вийде, бо це не std::string. Тут вже буде подвійна конвертація char[] -> std::string -> Entity. Це не відбудеться, бо не може бути двох implicit conversion.
Щоб це зробити, потрібно конвертувати літерал в std::string або використати конструктор класу Entity. В обох випадках відбувається тільки одна неявна конвертація.

```cpp
PrintEntity(std::string("Andriy"));
// або
PrintEntity(Entity("Andriy"));
```



```cpp
Entity a = std::string("Andriy");
```
 
### Explicit keyword. Це ключове слово пишеться перед конструктором, щоб відключити для цього конструктора можливість implicit conversion.

```cpp
#include <iostream>
#include <string>

class Entity {
private:
    std::string m_Name;
    int m_Age;
public:
    explicit Entity(const std::string& name): m_Name(name), m_Age(-1) {}
    explicit Entity(int age): m_Name("Unknown"), m_Age(age) {}

}

void PrintEntity(const Entity& entity) {
    std::cout << entity.GetName() << std::endl;
}

int main() {
    // explicit conversion
    Entity a = "Andriy"; // error
    Entity b = 22; // error

    PrintEntity(22); // errorc

    std::cin.get();
}
```