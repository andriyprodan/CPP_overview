```cpp
#include <iostream>

void HelloWorld(int a) {
    std::cout<<"Hello World! Value"<<a<<std::endl;
}

int main() {
    // creating custom type for the function
    typedef void(*HelloWorldFunction)(int);

    HelloWorldFunction function = HelloWorld;

    function(8); 
    function(9);

    std::cin.get();
}
```

## Another example. Passing function to another function.

```cpp
#include <iostream>
#include <vector>

void ForEach(const std::vector<int>& values, void(*func)(int)) {
    for (int value : values) {
        func(value);
    }
}


int main() {
    std::vector<int> values = {1, 5, 4, 2, 3};
    // using lambda function as the second parameter
    ForEach(values, [](int value) { std::cout<<"Value"<<value<<std::endl; });

    std::cin.get();
}
```