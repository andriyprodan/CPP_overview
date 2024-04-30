Перевага auto: якщо замінити тип повернення для функції GetName на char*, то не потрібно міняти цей тип в main. Таким чином потрібно менше міняти рядків коду. Але з іншого боку, це може зламати код, бо в main можуть викликатися функції std::string, і якщо змінити тип повернення на char*, то може виникнути помилка, бо в char* немає цих методів. Тому в такому випадку (повернення з функції) краще вказувати тип повернення явно. Окрім того, не ясно зразу, якого типу змінна name. Для того щоб це дізнаться, потрібно виконувать зайві рухи.

```cpp
#include <iostream>
#include <string>

std::string GetName() {
    return "Cherno";
}

int main() {
    auto name = GetName();
    // std::string name = GetName();

    std::cout<<name<<std::endl;

    std::cin.get();
}

```

Де auto дійсно може бути корисним:
```cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::strings> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");

    // замість того, що писати це:
    for (std::vector<str::string>::iterator it = strings.begin(); it!=strings.end(); it++) {
        std::cout<<*it<<std::endl;
    }

    // можна написати це:
    for (auto it = strings.begin(); it!=strings.end(); it++) {
        std::cout<<*it<<std::endl;
    }

    std::cin.get();
}

```

Інший приклад:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Device {};

class DeviceManager {
private:
    std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
    const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const {
        return m_Devices;
    }
}

int main() {
    DeviceManager dm;
    // Замість того, що писати це:
    const std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevices();

    // Можна написати це:
    const auto& devices = dm.GetDevices();

    std::cin.get();
}

```