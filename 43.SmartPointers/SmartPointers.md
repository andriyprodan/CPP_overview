### **Smart pointers** - метод для того, щоб автоматизувати процес видалення пам'яті, який використовується для об'єктів, які були створені за допомогою оператора new.
#### В даному випадку використовується **unique pointer**. Unique, тому що він може вказувати лише на один об'єкт. Якщо він вказує на один об'єкт, то на цей об'єкт не може вказувати інший unique pointer.

```cpp
#include <iostream>
#include <string>
#include <memory>

class Entity {
public:
    Entity() {
        std::cout<< "Created Entity" << std::endl;
    }

    ~Entity() {
        std::cout<< "Destroyed Entity" << std::endl;
    }

    void Print() {}
};

int main() {
    {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        // std::unique_ptr<Entity> e2 = entity; // видасть помилку компіляції, бо unique pointer не може вказувати на один об'єкт одночасно з іншим unique pointer
        entity->Print();
    }
    // automatically calls the destructor of Entity. Memory has been freed.

    std::cin.get();
}
```

### **Shared pointer** - він може вказувати на один об'єкт, але може бути кілька shared pointer, які вказують на цей об'єкт. Коли останній shared pointer, який вказує на об'єкт, видаляється, то відбувається видалення об'єкта. Під капотом використовує *reference counting*.

```cpp
int main() {
    {
        std::shared_ptr<Entity> e0;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity;
            // Shared pointer reference counting is 2.
        }
        // does not call the destructor of Entity. Memory has not been freed. e0 still points to the Entity, but not sharedEntity.
        // Shared pointer reference counting is 1.
    }
    // automatically calls the destructor of Entity. Memory has been freed. Shared pointer reference counting is 0.
    std::cin.get();
}
```

### **Weak pointer** - використовується для того, щоб посилатися на об'єкт, на який вказує shared pointer, але не збільшувати reference counting. Якщо об'єкт, на який вказує shared pointer, видаляється, то weak pointer стає невалідним.

```cpp
int main() {
    {
        std::weak_ptr<Entity> e0;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity;
            // Shared pointer reference counting is 1.
        }
        // automatically calls the destructor of Entity. Memory has been freed. Shared pointer reference counting is 0.
        // weak pointer is invalid. It does not call the destructor of Entity. 
    }
    
    std::cin.get();
}
```

#### Краще використовувать unique pointer, якщо можна. Бо використання shared pointer трохи повільніше, бо використовує reference counting. Але shared pointer може бути корисним, якщо об'єкт потрібно передавати в багато місць.