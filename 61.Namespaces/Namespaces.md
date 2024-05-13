```cpp
#include <iostream>
#include <string>

namespace apple {
    void print(const char* text) {
        std::cout<<text<<std::endl;
    } 

    void another_print(const char* text) {
        std::cout<<text<<std::endl;
    }
}

namespace orange {
    namespace functions {
        void print(const char* text) {
            std::string temp = text;
            std::reverse(temp.begin(), temp.end());
            std::cout<<temp<<std::endl;
        }
    }
}

int main() {
    using apple::another_print; // using only function another_print from namespace apple
    another_print("Hello");

    // here we still need to use namespace prefix
    apple::print("Hello");

    namespace or_f = orange::functions; // alias for namespace orange and nested namespace functions
    or_f::print("Hello");

    std::cin.get();
}
```