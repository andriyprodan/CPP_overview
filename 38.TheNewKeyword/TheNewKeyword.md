Коли ми пишемо **new int**, тобто виділяємо пам'ять в heap для цілого числа, то програма намагається знайти в пам'яті 4 послідовних незайнятих байти. Але є така штука (free list), яка помічає пам'ять, яка є вільною.

```cpp
class Entity {
private:
    String m_Name;
public:
    Entity(): m_Name("Unknown") {}
    Entity(const String& name): m_Name(name) {}

    const String& GetName() const {
        return m_Name;
    }
}

int main() {
    int a = 2;
    int* b = new int; // 4-byte integer allocated in heap

    int* arr = new int[50]; // 200-byte integer array allocated in heap

    // size of std::string ~ 32 bytes
    Entity* e = new Entity("Cherno"); // size of std::string (m_Name)

    Entity* e_arr = new Entity[50]; // size of std::string (m_Name) * 50

    // MUST delete allocated memory
    delete b;
    // to delete an array we use [] after delete
    delete[] arr;
    delete e;
    delete[] e_arr;
    

    std::cin.get();
}
```

#### Що відбувається під капотом
Алокує пам'ять для Entity і викликає конструктор
```cpp
Entity* e = new Entity();
```
Просто алокує пам'ять для Entity, без викликання конструктора. Так бажано не виділяти пам'ять.
```cpp
Entity* e = (Entity*)malloc(sizeof(Entity));
```