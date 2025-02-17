```cpp
#include <iostream>
#include <string>

class Entity {
public:
    virtual std::string GetName() {
        return "Entity";
    }
};

class Player: public Entity {
private:
    std::string m_Name;
public:
    Player(const std::string& name): m_Name(name) {}

    std::string GetName() override { return m_Name; }
};

void PrintName(Entity* entity) {
    std::cout << entity->GetName() << std:: endl;
}

int main() {
    Entity* e = new Entity();
    PrintName(e); // prints "Entity"

    Player* p = new Player("Cherno");
    PrintName(p); // prints "Cherno"

    Entity* entity = p;
    std::cout << entity->GetName() << std:: endl; // prints "Cherno"

    std::cin.get();
}
```

Для того щоб у функції PrintName викликався метод GetName класу Player, потрібно перевантажити цей метод. Позначить в базовому класі як virtual, а в дочірньому як override. Інакше навіть для дочірніх класів буде викликаться метод батьківського класу (на екран виведеться Entity).