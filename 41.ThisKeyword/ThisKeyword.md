### Ключове слово **this** - це вказівник на поточний об'єкт, для якого викликано метод. це слово використовується тільки в не статичних методах класу.
```cpp
#include <iostream>
#include <string>

void PrintEntity(const Entity& e);

class Entity {
public:
    int x, y;

    Entity(int x, int y) {
        Entity* const e = this; // не можна змінювати адресу пам'яті, на яку вказує вказівник this
        // this = nullptr; // помилка компіляції
        this->x = x;
        this->y = y;

        PrintEntity(*this);
    }

    int GetX() const {
        const Entity* const e = this; // не можна змінювати значення, на яке вказує вказівник this і адресу пам'яті, на яку вказує вказівник this
        // Entity* e1 = this; // видасть помилку компіляції
        // e->x = 2; // помилка компіляції
        return this->x;
    }
}

void PrintEntity(const Entity& e) {
    std::cout << e.GetX() << std::endl;
}


int main() {
    Entity e(5, 10);
    std::cout << e.x << ", " << e.y << std::endl;
    std::cin.get();
}
```