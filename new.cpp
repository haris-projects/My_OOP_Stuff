#include <iostream>
#include <string>

int main() {
    // 1. Output text to the console
    std::cout << "Hello, World!\n";

    // 2. Take user input
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Welcome to C++, " << name << "!\n\n";

    // 3. Basic math and a loop
    int limit = 5;
    std::cout << "Counting up to " << limit << ":\n";
    for (int i = 1; i <= limit; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
