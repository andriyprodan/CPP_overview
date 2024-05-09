```cpp
#include <iostream>

int main() {
    int** a2d = new int*[5];
    for (int i=0; i< 5; i++) {
        a2d[i] = new int[5];
    }

    a2d[0][0] = 0;
    a2d[0][1] = 1;
    a2d[0][2] = 2;

    // freeing memory
    for (int i=0; i< 5; i++) {
        delete[] a2d[i];
    }
    delete[] a2d;

    // 3d array
    int*** a3d = new int**[5];
    for (int i=0; i< 5; i++) {
        a3d[i] = new int*[5];
        for (int j=0; j< 5; j++) {
            a3d[i][j] = new int[5];
        }
    }

    a3d[0][0][0] = 0;

    // freeing memory
    for (int i=0; i< 5; i++) {
        for (int j=0; j< 5; j++) {
            delete[] a3d[i][j];
        }
        delete[] a3d[i];
    }

    delete[] a3d;


    std::cin.get();
}

```

Проблема з алокацією пам'яті таким чином полягає в тому, що ця пам'ять йде не послідовно, тобто "під"-масиви можуть знаходитись в різних місцях пам'яті. Це призводить до того, що пам'ять розбита на фрагменти, що призводить до погіршення продуктивності програми.

можна замість використання багатовимірних масивів використовувати одновимірні масиви з таким же розміром як і багатовимірні, але в даному випадку пам'ять буде послідовна

```cpp
#include <iostream>

int main() {
    int* a2d = new int[5 * 5];
    for (int y=0; y<5; y++) {
        for (int x=0; x<5; x++) {
            a2d[y * 5 + x] = 2;
        }
    }

    std::cin.get();
}
```