```cpp
#include <iostream>
#include <string>

namespace apple {
    void print(const std::string& text) {
        std::cout<<text<<std::endl;
    }
}

namespace orange {
    void print(const char* text) {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout<<temp<<std::endl;
    }
}

using namespace apple;

// print function from apple namespace is replaced with print function from orange namespace because type char* is more suitable.
using namespace orange;

int main() {
    print("Hello");
}
```

Ось чому потрібно використовувати префікси просторів імен, щоб було ясно, яка саме функція print використовується. 
```cpp
#include <iostream>
#include <string>

namespace apple {
    void print(const std::string& text) {
        std::cout<<text<<std::endl;
    }
}

namespace orange {
    void print(const char* text) {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout<<temp<<std::endl;
    }
}

int main() {
    apple::print("Hello");
    orange::print("Hello");
}
```

# Ніколи не використовуй using namespace в заголовочних файлах (.h) !

Можна використовувать using namespace  в менших блоках коду (функції, умови). 
```cpp
int main() {
    {
        using namespace apple;
        print("Hello");
    }
    {
        using namespace orange;
        print("Hello");
    }
}
```