```cpp
#include <iostream>

struct Vector2 {
    float x, y;
};

struct Vector4 {
    /* a occupies the same memory as x and y
       b occupies the same memory as z and w
       So we can represent Vector4 as two Vector2
       Or we can represent Vector4 as four floats
       But still this vector occupies memory of only 4 floats,
         not 8 floats.
         
    */

    union {
        struct {
            float x, y, z, w;
        };
        struct {
            Vector2 a, b;
        }
    };
};

void PrintVector2(const Vector2& vector) {
    std::cout << vector.x << ", " << vector.y << std::endl;
}

int main() {
    Vector4 vector = {1.0f, 2.0f, 3.0f, 4.0f};
    PrintVector2(vector.a); // prints 1, 2
    PrintVector2(vector.b); // prints 3, 4
    vector.z = 500.0f;
    std::cout << "---------------------" << std::endl;
    PrintVector2(vector.a); // prints 1, 2
    PrintVector2(vector.b); // prints 500, 4
    
    std::cin.get();
}
```