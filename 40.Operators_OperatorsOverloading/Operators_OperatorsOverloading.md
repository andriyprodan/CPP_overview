```cpp
#include <iostream>
#include <string>

struct Vector2 {
    float x, y;

    Vector2(float x, float y)
        : x(x), y(y) {}

    Vector2 Add(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator+(const Vector2& other) const {
        return Add(other);
    }

    Vector2 Multiply(const Vector2& other) const {
        return *this * other;
    }

    Vector2 operator*(const Vector2& other) const {
        return Vector2(x * other.x, y * other.y);
    }

    bool opearator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }

    bool opearator!=(const Vector2& other) const {
        return !(*this == other);
    }
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other) {
    stream << other.x << ", " << other.y << endl;
    return stream;
}

int main() {
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

    Vector2 result = position.Add(speed.Multiply(powerup));
    // or
    Vector2 result = position + speed * powerup;

    std::cout << result.x << ", " << result.y << std::endl;
    // or
    std::cout << result << std::endl; // prints "5.5, 9.0"

    if (result == Vector2(5.5f, 9.0f)) {
        std::cout << "Result is correct!" << std::endl;
    }

    if (result != Vector2(5.5f, 9.0f)) {
        std::cout << "Result is incorrect!" << std::endl;
    }


    std::cin.get();
}

```