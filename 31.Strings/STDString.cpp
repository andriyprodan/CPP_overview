#include <iostream>
#include <string>

void PrintString(const std::string& string) {
    std::cout << string << std::endl;
}

int main() {
    char* s = "Example";
    int s_len = strlen(s);

    std::string name = "Cherno";

    int name_len = name.size();
    name += " hello!";
    std::cout << name << std::endl;

    // check if a string contains a substring
    // std::string::npos - illegal value for the position of a character in a string
    bool contains = name.find("no") != std::string::npos; // true

    PrintString(name);


    std::string other_name = std::string("Charlie") + " hello!";

    std::cin.get();
}