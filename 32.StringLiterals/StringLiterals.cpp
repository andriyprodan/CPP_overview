#include <iostream>
#include <string>

int main() {
    // this is a string literal with a hidden null terminator. That's why the size of the array is 8, not 7 (6 characters + 1 other null terminator in the middle of the string)
    const char name[8] = "Che\0rno"; 
    std::cout << strlen(name) << std::endl; // prints 3, because strlen stops at the first null terminator

    // this is a string literal, it's immutable even without the const keyword
    // but some compilers will allow you to compile this code. But in general, it's not a good practice to do this.
    // It DOES NOT CREATE copy of the string literal in the memory
    char* name2 = "Cherno"; 
    // name2[2] = 'a'; // it didn't work even if the compilation was successful. third character is still 'e'

    char name3[] = "Cherno"; // this is a mutable string, it's stack allocated. It CREATES copy of the string literal in the memory
    name3[2] = 'a'; // it worked, now the third character is 'a'

    const wchar_t* name2 = L"ЧЕРНО"; // wide string literal, used for unicode characters

    const char16_t* name3 = u"ЧЕРНО"; // 16-bit unicode string literal
    const char32_t* name4 = U"ЧЕРНО"; // 32-bit unicode string literal

    // C++14 feature
    using namespace std::string_literals;

    std::string name0 = "Cherno"s + " hello!"; // error: invalid operands to binary expression ('const char *' and 'const char *')

    const char* example = R"(Line1
    Line2
    Line3
    Line4)"; // raw string literal, it ignores escape sequences (\n, \t, etc.)


    std::cin.get();
}