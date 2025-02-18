В більшості компіляторів не можливо робити масив, в якому за розмір виступає змінна(`int* arr = new int[n]`). Тому можна використати шаблони, для того, щоб створити масив з розміром, який вказується в шаблоні(`int N`).
```cpp
#include <iostream>
#include <string>

template<typename T, int N>
class Array {
private:
    T m_Array[N];
public:
    int GetSize() const {return N;}
};

// first initialization of Array is replaced with following in compile time
// class Array {
// private:
//     int m_Array[5];
// public:
//     int GetSize() const {return 5;}
// };

int main() {
    Array<int, 5> array;
    std::cout<<array.GetSize()<<std::endl;

    std::cin.get();
}
```