### Як неправильно робить.
В даному випадку при знищенні змінної poly викликається лише деструктор базового класу, а не деструктор похідного класу. Це тому, що деструктор базового класу не є віртуальним.

```cpp
#include <iostream>

class Base {
public:
    Base() { 
        std::cout << "Base Constructor" << std::endl;
    }
    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
}

class Derived : public Base {
public:
    Derived() { 
        m_array = new int[5];
        std::cout << "Derived Constructor" << std::endl;
    }
    ~Derived() {
        delete[] m_array; // memory leak <-------------------
        std::cout << "Derived Destructor" << std::endl;
    }
private:
    int* m_array;
}


int main() {
    Base* base = new Base(); // prints "Base Constructor"
    delete base; // prints "Base Destructor"
    std::cout << "---------------------" << std::endl;
    Derived* derived = new Derived(); // prints "Base Constructor", "Derived Constructor"
    delete derived; // prints "Derived Destructor", "Base Destructor"
    std::cout << "---------------------" << std::endl;
    Base* poly = new Derived(); // prints "Base Constructor", "Derived Constructor"
    delete poly; // prints ONLY "Base Destructor". "Derived Destructor" is not called. Memory is not freed.
    
    std::cin.get();
}
```

### Як правильно робить.
Щоб вирішити цю проблему, потрібно зробити деструктор базового класу віртуальним. Це дозволить викликати деструктор похідного класу при знищенні об'єкта базового класу.


```cpp
#include <iostream>

class Base {
public:
    Base() { 
        std::cout << "Base Constructor" << std::endl;
    }
    virtual ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
}

class Derived : public Base {
public:
    Derived() { 
        m_array = new int[5];
        std::cout << "Derived Constructor" << std::endl;
    }
    ~Derived() {
        delete[] m_array;
        std::cout << "Derived Destructor" << std::endl;
    }
private:
    int* m_array;
}


int main() {
    Base* poly = new Derived(); // prints "Base Constructor", "Derived Constructor"
    delete poly; // prints "Derived Destructor", "Base Destructor"
    
    std::cin.get();
}
```