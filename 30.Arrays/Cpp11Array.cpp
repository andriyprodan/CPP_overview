#include <iostream>
#include <array>

int main() {
    std::array<int, 5> data; // 5 - size of the array
    data[0] = 2;

    for (int i = 0; i < data.size(); i++) {
        data[i] = 2;
    }

    std::cin.get();
}