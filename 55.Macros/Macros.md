## Preprocessing - це етап до компіляції, коли всі директиви(рядки коду, що починається на хеш #) замінюються у всіх місцях коду, де вони згадуються. В даному прикладі LOG(x) замінюється на std::cout<<x<<std::endl. 

Якщо PR_DEBUG визначено, то LOG("Hello World") виведе "Hello World" в консоль. Якщо PR_DEBUG не визначено, то LOG("Hello World") не виведе нічого в консоль. PR_DEBUG можна визначити за допомогою прапорця -DPR_DEBUG=1 при компіляції. Таким чином на релізі можна вимкнути всі логи, а на дебагу увімкнути. Також ці прапорці можна визначити в IDE Visual Studio.

```cpp
#include <iostream>
#include <string>

#if PR_DEBUG == 1
#define LOG(x) std::cout<<x<<std::endl
#elif defined(PR_RELEASE)
#define LOG(x)
#endif

int main() {
    LOG("Hello World");
    std::cin.get();
}
```
