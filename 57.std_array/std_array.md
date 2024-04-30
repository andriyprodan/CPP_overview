## std::array має фіксований розмір, який можна визначити на етапі компіляції. Це означає, що ви не можете змінити розмір std::array під час виконання програми. На відміну від звичайних масивів, std::array має bounds checking, тобто ви не можете вийти за межі масиву.

```cpp
#include <iostream>
#include <array>

void PrintArray(int* array, unsigned int size) {
    for (int i = 0; i<size; i++) {

    }
}

// we don't need to pass size of array, because std::array has size() method
void PrintArray(const std::array<int, 5>& data) {
    for (int i = 0; i<data.size(); i++) {

    }
}

int main() {
    // 5 - number of elements in array
    std::array<int, 5> data;
    data[0] = 2;
    data[4] = 1;

    std::cin.get();
}
```