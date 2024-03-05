## Константи
MAX_AGE не може змінюваться  
Адресу, на яку вказує a МОЖНА змінювати, але НЕ МОЖНА змінювати вміст цієї адреси
```cpp
    const int MAX_AGE = 90;
    const int* a  = new int;
    // int const* a = new int; // те саме, що і попереднє

    *a = 2; // повертає помилку
    a = (int*)&MAX_AGE; // адресу, на яку вказує a, можна змінити
```

адресу, на яку вказує a НЕ можна змінювати, але МОЖНА змінювати вміст цієї адреси
```cpp
    int* const a = new int;
    *a = 2; // вміст цієї адреси можна змінити
    a = (int*)&MAX_AGE; // повертає помилку
    a = nullptr; // повертає помилку
```

адресу, на яку вказує a НЕ можна змінювати, НЕ МОЖНА змінювати вміст цієї адреси
```cpp
    const int* const a = new int;
    *a = 2; // повертає помилку
    a = (int*)&MAX_AGE; // повертає помилку
    a = nullptr; // повертає помилку
```

### const у класах
метод GetX не може змінювати жодного поля класу
```cpp
#include <iostream>

class Entity {
private:
    int m_X, m_Y;
public:
    int GetX() const { // працює тільки в класах
        m_X = 2; // повертає помилку
        return m_X;
    }

    void SetX(int x) {
        m_X = x;
    }
}

void PrintEntity(const Entity& e) {
    e = Entity(); // повертає помилку, бо посилання константне
    std::cout << e.GetX() << std::endl;
}

void main() {
    Entity e;
    PrintEntity(e);
}
```

Якщо не вказувати const у методі GetX, то він не буде працювати в функції PrintEntity, бо вона приймає константний об'єкт. А отже вона не може бути впевнена в тому, що метод GetX не змінить жодного поля класу.
```cpp
#include <iostream>

class Entity {
private:
    int m_X, m_Y;
public:
    int GetX() {
        m_X = 2; // не повертає помилку
        return m_X;
    }
}

void PrintEntity(const Entity& e) {
    std::cout << e.GetX() << std::endl; // повертає помилку, бо метод GetX не константний
}

void main() {
    Entity e;
    PrintEntity(e);
}
```


як повертати вказівник з класу (одне з полів класу), але щоб його вміст і адресу, на яку він вказує, не можна було змінювати поза класом
```cpp
class Entity {
private:
    int* m_X, m_Y; // m_X - вказівник на int, але m_Y - це просто int
    // Щоб m_X і m_Y були вказівниками:
    // int* m_X, *m_Y;
public:
    const int* const GetX() const {
        return m_X; // повертаємо вказівник, який не можна змінювати
    }

    void SetX(int x) {
        m_X = x;
    }
}
```

### ключове слово mutable дозволяє змінювати поля класу в константних методах
```cpp
#include <iostream>

class Entity {
private:
    int m_X, m_Y;
    mutable int var;
public:
    int GetX() const {
        var = 2; // не повертає помилку
        return m_X;
    }
}
```