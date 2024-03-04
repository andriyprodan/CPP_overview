#include <iostream>
#include <string>

class Entity {
protected:
    int X, Y;

    void Print() {}
public:
    Entity() {
        X = 0;
    }
};

class Player: public Entity {
public:
    Player() {
        X = 2; // no error because X is protected
        // Print(); // error: 'void Entity::Print()' is private within this context
    }
};

int main() {
    Entity e;
    // e.X = 2; // error: 'int Entity::X' is private within this context
    // e.Print(); // error: 'void Entity::Print()' is private within this context 

    std::cin.get();
}