```cpp
#include <iostream>
#include <string>

static int s_Level = 8;
static int s_Speed = 2;

int main() {
    s_Speed = s_Level > 5 ? 10 : 5;

    std::string rank = s_Level > 10 ? "Master" : "Beginner";

    s_Speed = (s_Level > 5 && s_Level) ? (s_Level > 10 ? 15 : 10) : 5; // три в одному (дужки можна прибрать). Пездець а не код, краще так не робить
    std::cout << s_Speed << std::endl;

    std::cin.get();
}
```