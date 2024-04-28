### Як працює std::vector під капотом
Коли викликається push_back, то весь вектор, елементи якого є об'єктами(не вказівниками), переноситься в повністю нове місце в пам'яті. Це робиться для того, щоб новому елемент, який було додано, вистачало місця в пам'яті, щоб всі елементи йшли одне за одним в пам'яті. Це називається reallocation. Це дуже дорога операція, оскільки весь вектор переноситься в нове місце в пам'яті, а старе місце в пам'яті видаляється. Це означає, що всі елементи вектора копіюються в нове місце в пам'яті. Це дуже дорога операція, оскільки вона має складність O(n), де n - кількість елементів вектора. Це означає, що якщо ми маємо вектор з 1000 елементів, і ми додаємо ще один елемент, то це буде дуже дорога операція, оскільки всі 1000 елементів вектора будуть скопійовані в нове місце в пам'яті.

#### Коли відбувається копіювання елементів вектора?
```cpp
#include <iostream>
#include <string>
#include <vector>

struct Vertex {
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z) {
    }

    Vertex(const Vertex& vertex): x(vertex.x), y(vertex.y), z(vertex.z) {
        std::cout << "Copied!" << std::endl;
    }
};

int main() {
    std::vector<Vertex> vertices;
    vertices.push_back(Vertex(1, 2, 3)); // prints "Copied!" because it creates a copy of the Vertex object that is passed to push_back
    vertices.push_back(Vertex(4, 5, 6)); // prints "Copied!" twice because it creates a copy of the Vertex object that is passed to push_back and also creates a copy of the Vertex object that already exists in the vector
    vertices.push_back(Vertex(7, 8, 9)); // prints "Copied!" three times because it creates a copy of the Vertex object that is passed to push_back and also creates a copies of two Vertex objects that already exists in the vector

    std::cin.get();
}
```

Щоб не викликати Copy constructor можна створювати об'єкт Vertex в пам'яті, яка вже була виділена для вектора. Це можна зробити за допомогою методу emplace_back. Окрім того, задавати місткість вектора спочатку, наприклад вказати, що вектор може містити 3 елементи, таким чином, вектор не буде переносити елементи в нове місце в пам'яті, поки не буде додано 4-й елемент.

```cpp

int main() {
    std::vector<Vertex> vertices;
    vertices.reserve(3); // reserve memory for 3 elements
    vertices.emplace_back(1, 2, 3); // cosntructs the Vertex object in the vector's memory with parameters 1, 2, 3
    vertices.emplace_back(4, 5, 6); 
    vertices.emplace_back(7, 8, 9); 

    std::cin.get();
}
```
