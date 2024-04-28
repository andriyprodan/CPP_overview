```cpp
#include <iostream>
#include <string>

template<typename T>
void Print(T value) {
    std::cout<<value<<std::endl;
}

int main() {
    Print<int>(5);
    Print<std::string>("Hello");
    Print<float>(5.5f);
    // or
    Print(5);
    Print("Hello");
    Print(5.5f);

    std::cin.get();
}
```