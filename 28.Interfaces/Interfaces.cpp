#include <iostream>
#include <string>

class Printable {
public:
    virtual std::string GetClassName() = 0; // pure virtual function (= 0)
};


class Entity: public Printable {
public:
    std::string GetClassName() override { return "Entity"; }
};

class Player: public Entity {
private:
    std::string m_Name;
public:
    Player(const std::string& name): m_Name(name) {}

    std::string GetClassName() override { return "Player"; }
};


void Print(Printable* obj) {
    std::cout << obj->GetClassName() << std::endl;
}

int main() {
    // Printable* pr = new Printable(); // error: cannot instantiate abstract class

    Entity* e = new Entity();
    Print(e); // prints "Entity"

    Player* p = new Player("Cherno");
    Print(p); // prints "Player"

    std::cin.get();
}